
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "gtagml-grammar.h"

#include "kernel/grammar/gtagml-parse-context.h"

#include "kernel/grammar/gtagml-parse-state.h"

#include "kernel/grammar/gtagml-parser.h"

#include "relae-graph/relae-parser.templates.h"

#include "global-types.h"

USING_KANS(GTagML)

GTagML_Grammar::GTagML_Grammar()
{
}

void GTagML_Grammar::init(GTagML_Parser& p, GTagML_Graph& g, GTagML_Parse_State& parse_state)
{
 pre_rule( "script-word", "(?:[^{}()\\[\\]\\s`;,:]|(?:\\w::?\\w))+" );
 pre_rule( "valid-tag-command-name", "[\\w@](?:[^{}()\\[\\]<>/\\s`;,.:]|(?:\\w+::?\\w))*" );
 pre_rule( "space-to-end-of-line", "[__\\t]* \\n" );
 pre_rule( "end-of-line", "[__\\t\\S]* \\n" );
 pre_rule( "single-space", "[__\\t]" );
// pre_rule( "single-dot", "[.]" );

 pre_rule( "blank-line-content", "[__\\t]* \\n" );

 pre_rule( "blank-line", " \\n [__\\t]* " );

 pre_rule( "blank-lines", " \\s*?\\n\\s* " );

 pre_rule( "tag-command-wrap-mode-indicator", ": :? \\.?" );

 Context gtagml_context = add_context("gtaml-context");
 //Context* raw_context = new Context( add_context("raw-context") );
 Context raw_context = add_context("raw-context");
 Context html_context = add_context("html-context");

 Context comment_context = add_context("comment-context");

 Context gtagml_or_html_context = add_context("gtaml-or-html",
   {gtagml_context, html_context});


 track_context({&gtagml_context, &raw_context,
   &gtagml_or_html_context, &html_context, &comment_context});

 switch(parse_state.current_parsing_mode())
 {
 case GTagML_Parsing_Modes::HTML:
  activate(gtagml_or_html_context);
  break;

 case GTagML_Parsing_Modes::Raw:
  activate(raw_context);
  break;

 case GTagML_Parsing_Modes::GTagML:
  activate(gtagml_context);
  break;
 }


 GTagML_Parse_Context& parse_context = parse_state.parse_context();

// size_t test;

 add_rule( flags_all_(parse_context ,after_auto_closed_tag_command),
   gtagml_context, "auto-closed-tag-command-leave",
   " [\\])}] "
   ,[&]
 {
  parse_state.auto_closed_tag_command_leave(p.match_text());
 });

// add_rule( gtagml_context, "sslashes",
//  " .space-to-end-of-line.+ \\(<-end->\\) "
//  " .single-space.* "
//  ,[&]
// {
//  parse_state.prepare_end_document();
// });

 add_rule( gtagml_context, "ell-3-plain",
   " ![.]{3}! "
   ,[&]
 {
  parse_state.primary_acc("...");
//  parse_state.ell_count(p.match_text().size(), "\\");
 });

 add_rule( gtagml_context, "suppress-latex",
   " (?<main> <!![\"'\\w()-]+!!>) .single-space.* "
   ,[&]
 {
  parse_state.primary_acc(p.matched("main"));
 });

 add_rule( gtagml_context, "suppress-sentence-switch-marker",
   " !(?<postpone> =?)>(?<extra> >?)"
   ,[&]
 {
  QString postpone = p.matched("postpone");
  QString extra = p.matched("extra");

  if(extra.isEmpty())
    parse_state.primary_acc("{\\sssm}");
  else
    parse_state.suppress_sentence_switch_marker(postpone);
 });




 add_rule( gtagml_context, "left-right-mid-processing-instruction",
   "  .space-to-end-of-line.* \\( (?<left> <*) (?<left-dash> -+) (?<instruction> [^-]*) (?<right-dash> -+) (?<right> >*) \\) "
   ,[&] //raw_context, &parse_state, this, &p]
 {
  QString lrcode = QString::number(p.matched("left").size())
    + QString::number(p.matched("left-dash").size())
    + QString::number(p.matched("right-dash").size())
    + QString::number(p.matched("right").size());

  QString instruction = p.matched("instruction");
  parse_state.parse_processing_instruction(instruction, lrcode);
 });


 add_rule( gtagml_context, "item-marker",
   "  (?<= \\n) (?: (?<pre> [\\S]+ ) .single-space.+ )? ~> .single-space.+ "
   ,[&] //raw_context, &parse_state, this, &p]
 {
  QString pre = p.matched("pre");

  parse_state.item_marker(pre);
 });


 add_rule( gtagml_context, "outer-tag-command-entry",
   " (?<blank-lines> .blank-lines.?) "
   " (?<outer> [[{(] )  (?<pre> [^\\s\\[\\]`]*) ` "
   " (?<main> (?: [^\\s\\[\\]`,;.] | (?: \\s+ ->> \\s+ ) )+ ) "
   " (?*supl* (?: ` (/- [^\\s\\[\\]`,;.]+ -/) )* ) "
   " (?<post> [,;.]+ )"
   ,[&] //raw_context, &parse_state, this, &p]
 {
  QString blank_lines = p.matched("blank-lines");

  QString outer = p.matched("outer");
  QString pre = p.matched("pre");
  QString main = p.matched("main");

  QStringVector supl; //? = p.rematched("supl");

  QString post = p.matched("post");

  parse_state.outer_tag_command_entry(blank_lines,
    outer, pre, main, supl, post);

 });

 add_rule( gtagml_context, "tag-command-entry-no-supl",
   " (?<blank-lines> .blank-lines.?) "
   " (?<outer> [[{(] )  (?<pre> [^\\s\\[\\]}`]*) ` "
   " (?<main> (?: [^\\s\\[\\]`,;.] | (?: \\s+ ->> \\s+ ) )+ ) "
   " (?<post> [,;.]+ )"
   ,[&] //raw_context, &parse_state, this, &p]
 {
  QString blank_lines = p.matched("blank-lines");

  QString outer = p.matched("outer");
  QString pre = p.matched("pre");
  QString main = p.matched("main");

  QStringVector supl; //? = p.rematched("supl");

  QString post = p.matched("post");

  parse_state.outer_tag_command_entry(blank_lines,
    outer, pre, main, supl, post);

 });



 add_rule( flags_all_(parse_context ,after_auto_closed_tag_command),
   gtagml_context, "tag-command-name-transform-entry",
   " \s+ => \s+ "
   ,[&]
 {
  parse_state.tag_command_name_transform_entry();
 });


 add_rule( flags_all_(parse_context ,inside_tag_command_name_transform),
   gtagml_context, "tag-command-name-transform-acc",
   " [^\\])}]+ | [\\])}] "
   ,[&]
 {
  parse_state.tag_command_name_transform_acc(p.match_text());
 });

 add_rule( gtagml_context, "outer-tag-command-leave",
   //?" (?<pre> [%+]* ` [\\w`-]+ )* ` (?<post> [\\])}] )"
   " (?<pre> [%+]* ` [\\w`-]+ )* ` (?<post> [\\])] )"
   ,[&]
 {
  QString pre = p.matched("pre");
  QString post = p.matched("post");

  parse_state.outer_tag_command_leave(pre, post);
 });






 add_rule( flags_all_(parse_context ,read_numbered_items),
   gtagml_context, "enums-item",
   " (?<= \\n (?: .single-space. | .single-space. .single-space.) )  ( ?<number> \\d+) (?<text> \\S*) (?<follow> [).]) "
   ,[&]
 {
  u2 number = p.matched("number").toShort();
  QString text = p.matched("text");
  QString follow = p.matched("follow");

  parse_state.enums_item(number, text, follow);
 });

 add_rule( flags_all_(parse_context ,read_numbered_items),
   gtagml_context, "enums-item_alt",
   " (?<= \\n) .single-space.* ( ?<number> \\d+) (?<text> \\S*) (?<follow> [).]) "
   ,[&]
 {
  u2 number = p.matched("number").toShort();
  QString text = p.matched("text");
  QString follow = p.matched("follow");

  parse_state.enums_item(number, text, follow);
 });







 add_rule( gtagml_context, "enter-multi-line-comment",
   " ; ;+ (?<tail> [~-]{2,}) "
   ,[comment_context, this, &p] //raw_context, &parse_state, this, &p]
 {
  QString tail = p.matched("tail");
  activate_with_depth_mark(comment_context, tail.length());
 });

 add_rule( gtagml_context, "single-line-comment",
   " ;{2,} [~=-] [^\\n]* \\n "
   ,[] //raw_context, &parse_state, this, &p]
 {
 });


 add_rule( gtagml_context, "latex-command-via-annotation",
   " @\\[(?<concept> \\w+):(?<text> [^\\]]+)\\] "
   ,[&]
 {
  QString concept = p.matched("concept");
  QString text = p.matched("text");

  parse_state.latex_command_via_semantic_annotation(concept, text);
 });


 add_rule( comment_context, "leave-multi-line-comment",
   " (?<tail> [~-]{2,}) ; ;+  "
   ,[gtagml_context, comment_context, this, &p] //raw_context, &parse_state, this, &p]
 {
  QString tail = p.matched("tail");
  check_activate_with_depth_mark(gtagml_context, comment_context, tail.length());
 });

 add_rule( flags_all_(parse_context ,emph_italics_mode),
   gtagml_context, "leave-emph-italics-mode",
   " /\\\\ (?=/) "
   ,[&]
 {
  parse_state.leave_emph_italics_mode();
 });

 add_rule( flags_all_(parse_context ,emph_italics_mode),
   gtagml_context, "leave-emph-italics-mode",
   " / (?!=/) "
   ,[&]
 {
  parse_state.leave_emph_italics_mode();
 });

 add_rule( gtagml_context, "enter-emph-italics-mode",
   " & (?<mid> =?) / "
   ,[&]
 {
  parse_state.enter_emph_italics_mode(p.matched("mid"));
 });


 add_rule( gtagml_context, "noindent-marker",
   " (?<! \\S) --- (?= \\S) "
   ,[&]
 {
  parse_state.noindent_marker();
 });



 add_rule( gtagml_context, "ell-count-restrict-space",
   " [.]{3} (?= \\s) "
   ,[&]
 {
  parse_state.ell_count(p.match_text().size(), "\\");
 });

 add_rule( gtagml_context, "ell-2-nonbreak",
   " [.]{2} (?= [^\\s.]) "
   ,[&]
 {
  parse_state.ell_2_nonbreak();
 });

 add_rule( gtagml_context, "ell-count",
   " [.]{2,} "
   ,[&]
 {
  parse_state.ell_count(p.match_text().size());
 });


 add_rule( gtagml_context, "single-slash-and-consume-blank-lines",
  " \n (?<first> /\\+) \\s* (?=\\n) "
  ,[&]
 {
  parse_state.single_slash_line_plus();
 });

 add_rule( gtagml_context, "single-slash-line",
  " \n (?<first> /) .single-space.* (?=\\n) "
  ,[&]
 {
  parse_state.single_slash_line();
 });

// add_rule( gtagml_context, "single-slash-line",
//  " \n (?<first> /) .single-space.* (?=\\n) "
//  ,[&]
// {
//  parse_state.single_slash_line();
// });

 add_rule( gtagml_context, "enter-latex-only-to-space--leave-space",
  " .single-space.* (?<m> -%>>) (?<sp> .single-space.*)  "
  ,[&]
 {
  // //  is this ok here?
  parse_state.primary_acc(p.matched("sp"));
  parse_state.enter_latex_only_to_space(p.matched("m"));
 });


 add_rule( gtagml_context, "enter-latex-only-to-space",
  " .single-space.* (?<m> -%>) .single-space.*  "
  ,[&]
 {
  parse_state.enter_latex_only_to_space(p.matched("m"));
 });



 add_rule( flags_all_(parse_context ,latex_only_to_space),
  gtagml_context, "leave-latex-only-to-space--consume-space",
  " (?<m> _) (?= \\s) "
  ,[&]
 {
  parse_state.leave_latex_only_to_space(p.matched("m"));
 });


 add_rule( flags_all_(parse_context ,latex_only_to_space),
  gtagml_context, "leave-latex-only-to-space",
  " .single-space.+ (?=\\S) "
  ,[&]
 {
  parse_state.leave_latex_only_to_space("");
 });

 add_rule( flags_all_(parse_context ,latex_only_to_space),
  gtagml_context, "leave-latex-only-to-space-at-newline",
  " .single-space.* (?=\\n) "
  ,[&]
 {
  parse_state.leave_latex_only_to_space("");
 });


// add_rule( gtagml_context, "immediate-latex-only",
//  " -%>> (?<text>\\S+) "
//  ,[&]
// {
//  QString m = p.matched("text");
//  parse_state.latex_only(m);
// });




 add_rule( gtagml_context, "enter-latex-only--leave-space",
  " (?<m> <<-%) \\s* "
  ,[&]
 {
  parse_state.enter_latex_only(p.matched("m"));
 });

 add_rule( gtagml_context, "enter-latex-only",
  " \\s+ (?<m> <-%) \\s* "
  ,[&]
 {
  parse_state.enter_latex_only(p.matched("m"));
 });

 add_rule( flags_all_(parse_context ,latex_only),
   gtagml_context, "leave-latex-only--leave-space",
   " \\s* (?<m> %->>) "
   ,[&]
 {
  parse_state.leave_latex_only(p.matched("m"));
 });


 add_rule( flags_all_(parse_context ,latex_only),
   gtagml_context, "leave-latex-only",
   " \\s* (?<m> %->) \\s* "
   ,[&]
 {
  parse_state.leave_latex_only(p.matched("m"));
 });




 add_rule( gtagml_context, "footnote-marker",
   " \\\\ (?<number> \\d+) (?= [\\s)%]) "
   ,[&]
 {
  parse_state.footnote_marker(p.matched("number"));
 });


 add_rule( gtagml_context, "force-switch-sentence",
  " => \\s "
  ,[&]
 {
  parse_state.force_switch_sentence();
 });

 add_rule( gtagml_context, "force-end-sentence-mark",
  " !=< (?<follow> ;?) \\s "
  ,[&]
 {
  QString follow = p.matched("follow");
  parse_state.force_end_sentence_mark(follow);
 });

 add_rule( gtagml_context, "enter-sentences-latex-filter",
  " (?<pretext> [~-]+) > (?= [\\\\$]) "
  ,[&]
 {
  parse_state.enter_sentences_latex_filter(p.matched("pretext"));
 });

 add_rule( gtagml_context, "leave-sentences-latex-filter",
  " (?<= [}$]) < (?<pretext> [~-]+) "
  ,[&]
 {
  parse_state.leave_sentences_latex_filter(p.matched("pretext"));
 });


 add_rule( gtagml_context, "enter-sentences-only",
  " (?<pre-space> (?: .single-space.* \\n .single-space.*) | "
  "  (?: .single-space.+ ) ) "
  " (?<open> <{0,2}) \\{ (?![[%<>`-]) "
  ,[&]
 {
  parse_state.enter_sentences_only(p.matched("open"), p.matched("pre-space"));
 });

 add_rule( flags_all_(parse_context ,sentences_only),
   gtagml_context, "leave-sentences-only",
   " \\} (?<close> >{0,2}) "
   " (?<post-space> .single-space.* \\n? .single-space.*) "
   ,[&]
 {
  parse_state.leave_sentences_only(p.matched("close"), p.matched("post-space"));
 });

 add_rule( flags_all_(parse_context ,read_parens_as_label),
   gtagml_context, "exs-blank-line",
   " (?: \\n \\s*){2,} "
   ,[&]
 {
  parse_state.blank_line_as_visible_space();
 });

 add_rule( flags_all_(parse_context ,read_parens_as_ref),
   gtagml_context, "paren-ref",
   " \\( (?<number> \\d+ ) (?<text> \\S*) \\) "
   ,[&]
 {
  parse_state.paren_ref(p.matched("number").toShort(), p.matched("text"));
 });

 add_rule( flags_all_(parse_context ,read_parens_as_ref),
   gtagml_context, "paren-ref-global",
   " \\(! (?<number> \\d+ ) (?<text> \\S*) \\) "
   ,[&]
 {
  parse_state.paren_ref_global(p.matched("number").toShort(), p.matched("text"));
 });


 add_rule( gtagml_context, "enter-justline",
   "  \\{% (?<pretext> -+ ) "
   ,[&]
 {
  parse_state.enter_justline(p.matched("pretext"));
 });


 add_rule( flags_all_(parse_context ,justline),
   gtagml_context, "leave-justline",
   " (?<pretext> \\s* [|-]+) % (?<follow> \\s* = \\d [\\d.]* )? \\s* \\}  "
   ,[&]
 {
  parse_state.leave_justline(p.matched("pretext"), p.matched("follow"));
 });


 add_rule( flags_all_(parse_context ,heading_acc),
   gtagml_context, "leave-heading",
   " (?= \\n) "
   ,[&]
 {
  parse_state.leave_heading();
 });


 add_rule( gtagml_context, "slashes",
  " .space-to-end-of-line.+ (?<first> /+) .single-space.+ (?<second> /*) "
  " .single-space.* " // (?<text> [^\\n]*) "
  ,[&]
 {
  QString first = p.matched("first");
  QString second = p.matched("second");
  // QString text = p.matched("text");

  parse_state.enter_heading(first.size(), second.size());

 });

// single-dot

 add_rule( gtagml_context, "end-sentence",
   " (?<punctuation> [!?.]) (? (?=\\s{2,}) | (?= \\n) )"
//   " (?<punctuation> [!?:.]) (\\s{2,} | \\n)"
   ,[&]
 {
  parse_state.end_sentence(p.matched("punctuation"));
 });

 add_rule( gtagml_context, "manual-end-sentence",
   "\\\\[.]/"
   ,[&]
 {
  parse_state.end_sentence();
 });

// -.>

 add_rule( gtagml_context, "pseud-paragraph",
   " - \\. > "
   ,[&]
 {
  parse_state.pseudo_paragraph();
 });

 add_rule( gtagml_context, "special-section",
   " .blank-lines. %\\. \\s* (?<text> \\S+) \\s+"
   ,[&]
 {
  parse_state.enter_special_section(p.matched("text"));
 });

 add_rule( gtagml_context, "subparagraph",
   " .blank-lines.  %\\/ \\s* (?<text> \\S+) (?:\\s* = (?<sup>\\S+))? \\s+"
   ,[&]
 {
  parse_state.enter_subparagraph(p.matched("text"), p.matched("sup"));
 });

 add_rule( gtagml_context, "enter-auto-paragraph-mode",
   " />> "
   ,[&]
 {
  parse_state.enter_auto_paragraph_mode();
 });

 add_rule( flags_all_(parse_context ,read_parens_as_label),
   gtagml_context, "exs-item",
   " \\( (?<number> \\d+) (?<text> \\S*) \\) "
   ,[&]
 {
  u2 number = p.matched("number").toShort();
  QString text = p.matched("text");
  parse_state.exs_item(number, text);
 });

 add_rule( flags_all_(parse_context ,read_desc_label),
   gtagml_context, "desc-item",
   " \\[\\| (?<text> [^|]+) \\|\\] "
   ,[&]
 {
  QString text = p.matched("text");
  parse_state.desc_item(text);
 });

 add_rule( flags_all_(parse_context ,read_desc_label),
   gtagml_context, "desc-item-with-multiline-label",
   " \\[; (?<text> [^;]+) ;\\] "
   ,[&]
 {
  QString text = p.matched("text");
  parse_state.desc_item_with_multiline_label(text);
 });

 add_rule( flags_all_(parse_context ,ignore_blank_lines),
   gtagml_context, "consume-blank-line",
//?   " (?<=\\n) .blank-line-content. "
   " .single-space.* \\n .blank-line-content. "
   ,[&]
 {
  parse_state.check_blank_line();
//  parse_state.show_latex();
 });


 add_rule( flags_all_(parse_context ,read_bulleted_items),
   gtagml_context, "bulleted-item",
   " (?<= \\s) (?<symbol> \\*+) (?<supp> [^*/\\s]*) (?=\\s) "
   ,[&]
 {
  QString symbol = p.matched("symbol");
  QString supp = p.matched("supp");
  parse_state.bulleted_item(symbol, supp);
 });


 add_rule( flags_all_(parse_context ,auto_paragraph_mode),
   gtagml_context, "auto-new-paragraph",
   " \\s* \\n .single-space.* \\n"
   ,[&]
 {
  parse_state.auto_new_paragraph();
 });


 add_rule( gtagml_context, "enter-italics-mode",
   " \\*/ "
   ,[&]
 {
  parse_state.enter_italics_mode();
 });

 add_rule( flags_all_(parse_context ,italics_mode),
   gtagml_context, "leave-italics-mode",
   " (?<pre-guard> ['\"]?) /\\* "
   ,[&]
 {
  QString pre_guard = p.matched("pre-guard");

  // //  prevents '/* being parsed as single-quote, etc.
  if(!pre_guard.isEmpty())
    parse_state.primary_acc(pre_guard);

  parse_state.leave_italics_mode();
 });


 add_rule( gtagml_context, "enter-block-float-mode",
   " \\s* \\[-> "
   ,[&]
 {
  parse_state.enter_block_float_mode();
 });

 add_rule( flags_all_(parse_context ,block_float_mode),
   gtagml_context, "leave-block-float-mode",
   " \\s* ->\\] "
   ,[&]
 {
  parse_state.leave_block_float_mode();
 });


 add_rule( gtagml_context, "latex-command-auto-closed",
   " ` (?<cmd-name> \\w+) (?: < (?<arg> [^>]+) > )?; "
   ,[&]
 {
  parse_state.latex_command_auto_closed(p.matched("cmd-name"),
    p.matched("arg"));
 });

 add_rule( gtagml_context, "citation",
   " \\[/ (?<label> [^:;*/]+) (?: (?<locator> [^/]*) )? /\\] "
   ,[&]
 {
  parse_state.citation(p.match_text(), p.matched("label"), p.matched("locator"));
 });

 add_rule( gtagml_context, "enter-footnote",
   " \\{< (?<pretext> [~_-]*) (?<space> \\s+)  "
   ,[&]
 {
  parse_state.enter_footnote(p.matched("pretext"), p.matched("space"));
 });

 add_rule( gtagml_context, "leave-footnote",
   " (?<space> \\s+) (?<pretext> [~_-]*) >\\} "
   ,[&]
 {
  parse_state.leave_footnote(p.matched("pretext"), p.matched("space"));
 });

 add_rule( flags_all_(parse_context ,acronym_mode),
   gtagml_context, "leave-acronym-mode",
   " / "
   ,[&]
 {
  parse_state.leave_acronym_mode();
 });

 add_rule( flags_all_(parse_context ,short_macro_mode),
   gtagml_context, "leave-short-maco-mode",
   " / "
   ,[&]
 {
  parse_state.leave_short_macro_mode();
 });

 add_rule( flags_all_(parse_context ,emph_sample_mode),
   gtagml_context, "leave-sample-mode",
   " / ; (?! ;) "
   ,[&]
 {
  parse_state.leave_sample_mode();
 });

 add_rule( flags_all_(parse_context ,emph_sample_mode),
   gtagml_context, "leave-sample-mode",
   " / (?! \\w) "
   ,[&]
 {
  parse_state.leave_sample_mode();
 });

 add_rule( flags_all_(parse_context ,emph_sample_mode),
   gtagml_context, "leave-sample-mode",
   " / (?! \\w) "
   ,[&]
 {
  parse_state.leave_sample_mode();
 });

 add_rule( flags_all_(parse_context ,emph_highlight_mode),
   gtagml_context, "leave-highlight-mode",
   " / "
   ,[&]
 {
  parse_state.leave_highlight_mode();
 });

 add_rule( gtagml_context, "enter-acronym-mode",
   " (?<pre> ;+) / (?=\\w) "
   ,[&]
 {
  QString pre = p.matched("pre");
  parse_state.enter_acronym_mode(pre.size());
 });

 add_rule( gtagml_context, "enter-short-macro-mode",
   " (?<pre> ,+) / (?=\\w) "
   ,[&]
 {
  parse_state.enter_short_macro_mode(p.matched("pre").size());
 });

 add_rule( gtagml_context, "short-macro",
   " (?<=\\s) (?<pre> ,+) (?<text> \\S+) "
   ,[&]
 {
  QString text = p.matched("text");
  parse_state.short_macro(text, p.matched("pre").size());
 });

 add_rule( gtagml_context, "short-acronym",
   " (?<=\\s) (?<pre> ;+) (?<text> \\S+) "
   ,[&]
 {
  QString text = p.matched("text");
  parse_state.short_acronym(text, p.matched("pre").size());
 });


 add_rule( gtagml_context, "emph-symbolic",
   " @/ (?<text> [^;,:/\\s-]+) "
   ,[&]
 {
  QString text = p.matched("text");
  parse_state.emph_symbolic(text);
 });



 add_rule( gtagml_context, "hyperlink-1",
   " \\[< (?<text> (?: [^>] | >[^\\]])+ ) \\s+ & \\s+ "
   " (?<link> (?: [^>] | >[^\\]])+ ) >\\] "
   ,[&]
 {
  QString text = p.matched("text");
  QString link = p.matched("link");
  parse_state.hyperlink_2(text.simplified(), link.simplified());
 });



 add_rule( gtagml_context, "hyperlink-1",
//           " \\[ < (?<text> (?: [^>] | >[*\\]])+ ) > \\] "
   " \\[ < (?<text> (?: [^>] | > [^\\]])+ ) > \\] "
   ,[&]
 {
  QString text = p.matched("text");
  parse_state.hyperlink_1(text.simplified());
 });


 add_rule( flags_all_(parse_context ,double_quote_mode),
   gtagml_context, "leave-double-quote-mode",
   " /\" "
   ,[&]
 {
  parse_state.leave_double_quote_mode();
 });

 add_rule( gtagml_context, "enter-double-quote-mode",
   " \"(?<pre> [\\w!] *)/ "
   ,[&]
 {
  parse_state.enter_double_quote_mode(p.matched("pre"));
 });



 add_rule( flags_all_(parse_context ,single_quote_mode),
   gtagml_context, "leave-single-quote-mode",
   " /' "
   ,[&]
 {
  parse_state.leave_single_quote_mode();
 });

 add_rule( gtagml_context, "enter-single-quote-mode",
   " '/ "
   ,[&]
 {
  parse_state.enter_single_quote_mode();
 });



 add_rule( flags_all_(parse_context ,single_quote_mode_doubled),
   gtagml_context, "leave-single-quote-mode-doubled",
   " /'' "
   ,[&]
 {
  parse_state.leave_single_quote_mode_doubled();
 });

 add_rule( gtagml_context, "enter-single-quote-mode-doubled",
   " ''(?<pre> \\w*)/ "
   ,[&]
 {
  parse_state.enter_single_quote_mode_doubled();
 });



 add_rule( flags_all_(parse_context ,single_quote_mode_trebled),
   gtagml_context, "leave-single-quote-mode-trebled",
   " /''' "
   ,[&]
 {
  parse_state.leave_single_quote_mode_trebled();
 });

 add_rule( gtagml_context, "enter-single-quote-mode-trebled",
   " '''(?<pre> \\w*)/ "
   ,[&]
 {
  parse_state.enter_single_quote_mode_trebled();
 });

 add_rule( gtagml_context, "special-character-sequence",
   " (?: %-+ ) | (?: \\^: ) | (?: %[%,$&#]) "
   ,[&]
 {
  QString m = p.match_text();
  parse_state.special_character_sequence(m);
 });




// add_rule( gtagml_context, "slashes",
//  " (?<first> /+)  .single-space.+  (?<second> /*) "
//  ,[&]
// {
//  QString first = p.matched("first");
//  QString second = p.matched("second");
//  QString text = p.matched("text");

//  parse_state.heading(first.size(), second.size(), text);
// });



 add_rule( gtagml_context, "primary-acc-newline",
  " .single-space.+ \\n "
           ,[&]
 {
  parse_state.primary_acc("\n");
 });

 add_rule( gtagml_context, "primary-acc",
  " . "
           ,[&]
 {
  parse_state.primary_acc(p.match_text());
 });

}
