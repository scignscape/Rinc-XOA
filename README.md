
# Rinc-XOA : Research in nonprofit contexts - Executable Open Access

If you are interested particularly in the <span style='color:#365450;background:#ede8ff'>RedPatch</span> Community Health research platform, 
that's detailed in this repository's <span style='color:#365450;background:#ede8ff'>RedPatch</span> branch or [skip ahead](#red-patch).

For a description of several projects that employed some of the code published here, 
including a list of open-access articles and book chapters, scroll down or [skip ahead](#sample-documents-raised).

Many of these components are built around a new Virtual Machine generator called 
"<span style='color:#365450;background:#ede8ff'>Qynviper</span>"; for details on that, scroll down or [skip ahead](#qynviper).


---

### Overview

In publishing, Diamond (<span style='color:#365450;background:#ede8ff'>DiamondOA</span>) is the most complete Open Access model, with no fees either for authors (i.e., Article Processing Charges 
(<span style='color:#365450;background:#ede8ff'>APC</span>s)) or readers (i.e., article paywalls).  The work needed to prepare manuscripts for publication is either performed on a volunteer basis or supported by "Diamond Open Access Funds", which are more prevalent in the European Union than the United State.

Meanwhile, Executable Research Objects (<span style='color:#365450;background:#ede8ff'>ERO</span>s) are one form of Research Object/data set guided by data transparency and <span style='color:#365450;background:#ede8ff'>FAIRsharing</span> (Findable, Accessible, Interoperable, Reusable) principles.  Research Objects in general may include multiple forms of digital assets (text, code, raw data files, and perhaps multimedia content) which can present challenges for in-depth usage.  An *Executable* Research Object in particular provides a single Research Application that serves as an entry point or overarching resource streamlining access to the variegated parts of a data publication.  In general, these Research Applications are standalone desktop-style programs which, when launched, will provide visual summaries and windows to manage data set records, as well as viewers for other media types (<span style='color:#365450;background:#ede8ff'>PDF</span> documents, images, videos, digital maps, etc.).

For the current repository and siblings, Executable Open Access (<span style='color:#365450;background:#ede8ff'>XOA</span>) designates a synthesis of these two paradigms.  Most FAIRsharing projects, to be sure, are Open Access by default because they are hosted on free services such as Open Science Framework (<span style='color:#365450;background:#ede8ff'>OSF</span>) or Dryad -- often linked to publications via "Data Availability" or "Supplemental Materials" sections on articles' landing pages (which also have abstracts, bibliographies, and so forth).  There is no such thing as a "dataset processing charge".  Nonetheless, <span style='color:#365450;background:#ede8ff'>ERO</span>s are most productive when they include complete version of associated research articles -- both in human-readable (e.g., <span style='color:#365450;background:#ede8ff'>PDF</span>) and machine-readable (e.g., <span style='color:#365450;background:#ede8ff'>JATS</span> <span style='color:#365450;background:#ede8ff'>XML</span>) formats, which requires that the entire package be governed by a <span style='color:#365450;background:#ede8ff'>DiamondOA</span> licence.  Moreover, aggregating disparate dataset materials into an overarching Research Application requires additional programming that could potentially be supported by <span style='color:#365450;background:#ede8ff'>DiamondOA</span> funds or similar initiatives.  In short, the <span style='color:#365450;background:#ede8ff'>ERO</span> and <span style='color:#365450;background:#ede8ff'>DiamondOA</span> paradigms are sufficiently interrelated/overlapping that each may help promote the other.

</span>Rinc-XOA</span> (this repository) has a sibling repo called <span style='color:#365450;background:#ede8ff'>DogLeash</span> (Diamond Object Grid - Language Server and Script Host), at [github.com/ScignScape/DogLeash](https://github.com/scignscape/DogLeash/) which holds most of the actual code.  This code base is intended to provide tools and templates for Executable Research Objects.  <span style='color:#365450;background:#ede8ff'>DogLeash</span> provides several "modules" for specific subject areas and implementation requirements, such as Medical Imaging, Geographic Information Systems, and Compiler Extensions.  A <span style='color:#365450;background:#ede8ff'>Rinc-XOA</span> project can include any modules relevant to its topic.

---

<a id="red-patch"></a>

### Qynviper Modules

A Qynviper VM -- "query/native interop compiler" -- can be implemented via code published in <span style='color:#365450;background:#ede8ff'>RedPatch</span>.  The idea 
behind Qynviper is that opcodes delegate to methods in <span style='color:#365450;background:#ede8ff'>C++</span> classes (or potentially those of other languages).  Each such class is called a "module".  By selecting a group of modules, individual VMs can target capabilities to their use-cases.  For example, a VM may be engineered as a compilation target for imperative/procedure scripting languages -- with support for lexical scopes, variables, function calls, and so forth -- but in other use-cases -- e.g., object deserialization -- VM blocks are generated from <span style='color:#365450;background:#ede8ff'>XML</span> or <span style='color:#365450;background:#ede8ff'>JSON</span> sources which are declarative rather than imperative.  A conventional <span style='color:#365450;background:#ede8ff'>C++</span> <span style='color:#365450;background:#ede8ff'>SAX</span> parser responds immediately to <span style='color:#365450;background:#ede8ff'>XML</span> parsing events, thereby conflating <span style='color:#365450;background:#ede8ff'>DTD</span> and handler logic, whereas a VM can partition the problem into two almost entirely separate domains (generating VM instruction sequences versus implementing opcode handlers).  The Qynviper components make heavy use of preprocessor macros, and in general it takes just a few minutes to rig up <span style='color:#365450;background:#ede8ff'>C++</span> classes as modules once the actual opcode methods are implemented.

The <span style='color:#365450;background:#ede8ff'>RedPatch</span> sources (outlined next) are built 
around several VMs created in this manner, partly for demonstration purposes.  This includes document processors for publications -- see the sample "Ordering Concepual Synthesis" paper linked below, or 
[here](https://scignscape.github.io/Rinc-XOA/authors/NathanielChristen/OrderingConceptualSynthesis.pdf).  The paper provides links to five other representations targeting different text-encoding specifications, such as <span style='color:#365450;background:#ede8ff'>RO-Crate</span> and <span style='color:#365450;background:#ede8ff'>TAGML</span> (Text-As-Graph Markup Language).  Here, these are not markup formats directly (though when needed convertable to/from <span style='color:#365450;background:#ede8ff'>XML</span> or <span style='color:#365450;background:#ede8ff'>JSON</span>) but rather Qynviper code used at different points in a publishing workflow.

**_AMPATH Forms_**

In addition to document preparation, <span style='color:#365450;background:#ede8ff'>RedPatch</span> illustrates other VM examples for use-cases such as object deserialization.  For instance, one Qynviper module is built around <span style='color:#365450;background:#ede8ff'>AMPATH</span> -- the "Academic Model Providing Access To Healthcare" -- which sponsors Electronic Health Record software used by NGOs such as Doctors Without Borders.  Although eventually rendered as <span style='color:#365450;background:#ede8ff'>HTML</span> (via <span style='color:#365450;background:#ede8ff'>ReactJS</span>) these records are intrinsically defined as <span style='color:#365450;background:#ede8ff'>JSON</span> configuration files, which opens the possibility for generating alternative front-end viewers.  The <span style='color:#365450;background:#ede8ff'>RedPatch</span> branch shows an example where <span style='color:#365450;background:#ede8ff'>AMPATH</span> forms are translated to <span style='color:#365450;background:#ede8ff'>C++</span> <span style='color:#365450;background:#ede8ff'>Qt</span> classes and compiled as ordinary desktop libraries (or standalone applications).  Such a "native rendering engine" is potentially useful in providing an <span style='color:#365450;background:#ede8ff'>EHR</span> framework which does not depend on <span style='color:#365450;background:#ede8ff'>HTTP</span> servers and client/server networking, and it also shows how <span style='color:#365450;background:#ede8ff'>AMPATH</span> annotations (with sources such as Open Concept Lab and other biomedical controlled vocabularies) can augment the searchability and interoperability of <span style='color:#365450;background:#ede8ff'>C++</span> <span style='color:#365450;background:#ede8ff'>GUI</span> components.  The role of Qynviper here is one of generating <span style='color:#365450;background:#ede8ff'>C++</span> code: <span style='color:#365450;background:#ede8ff'>AMPATH</span> configuration files are first parsed into VM scripts which are separately executed to create the final <span style='color:#365450;background:#ede8ff'>GUI</span> code.

**_DCMTK_**

Another similar example, based on <span style='color:#365450;background:#ede8ff'>XML</span> rather than <span style='color:#365450;background:#ede8ff'>JSON</span>, provides an extension to the widely-used <span style='color:#365450;background:#ede8ff'>DCMTK</span> library for working with <span style='color:#365450;background:#ede8ff'>DICOM</span> (Digital Imaging and Communications in Medicine) series.  This library offers multiple utilities for converting <span style='color:#365450;background:#ede8ff'>DICOM</span> files to other image and data formats (<span style='color:#365450;background:#ede8ff'>XML</span>, <span style='color:#365450;background:#ede8ff'>HTML</span>, <span style='color:#365450;background:#ede8ff'>JPEG</span> and so forth) but currently lacks support for other diagnostic-imaging formats, such as <span style='color:#365450;background:#ede8ff'>MI-CDM</span> (Medical Imaging Common Data Model), 
part of the <span style='color:#365450;background:#ede8ff'>OMOP-CDM</span> (Observational Medical Outcomes Partnership) Common Data Model.  For publishing medical-imaging research (topics such as AI Segmentation and Neuroimaging) it would also be helpful to map <span style='color:#365450;background:#ede8ff'>DSR</span> (Structured Reporting) observations, annotations, and "key" images onto common Open Science formats such as <span style='color:#365450;background:#ede8ff'>RO-Crate</span>.  For these use-cases, <span style='color:#365450;background:#ede8ff'>RedPatch</span> provides a Qynviper VM whose purpose is to parse <span style='color:#365450;background:#ede8ff'>dcm2xml</span> and <span style='color:#365450;background:#ede8ff'>dsr2xml</span> output and dispatch calls to code-generators for formats not currently supported by <span style='color:#365450;background:#ede8ff'>DCMTK</span>.

As a mostly self-contained platform, Qynviper VMs can readily be embedded in host applications, such as <span style='color:#365450;background:#ede8ff'>3DSlicer</span> (the preeminent research tool for medical imaging and <span style='color:#365450;background:#ede8ff'>DICOM</span> series).

---

<a id="red-patch"></a>

### Community Health Research Platform

I have grouped most of the $\colorbox{#ede8ff}{\color{#365450}{\text{DogLeash}}}$ modules into <span style='color:red!10!blue;background:#ede8ff'>RedPatch</span> (Research Objects - Diamond Open Access Targeting Children's and Community Health) which has its own branch in the current repository.  This code base leverages similarities between Electronic Health Records and Executable Research Object "microcomponents".  More specifically, at least for <span style='color:#365450;background:#ede8ff'>DogLeash</span> an Executable Research Object is composed of multiple microcomponents which, in general, each provide one application window and present the user with information and/or graphics from a particular data profile, multimedia resource, or record source (data base, data set, <span style='color:#365450;background:#ede8ff'>CSV</span>/</span>XML</span>/</span>JSON</span> file, etc.).  A good example of microcomponents would be displays showing a specific type of <span style='color:#365450;background:#ede8ff'>EHR</span> form, or a single medical image alongside provenance, diagnostic, and annotation metadata.  In <span style='color:#365450;background:#ede8ff'>DogLeash</span>, for each microcomponent there is typically a single <span style='color:#365450;background:#ede8ff'>C++</span> class encapsulating the totality of information provided by one instance of the component, plus metadata about valid ranges/values for form fields and annotations on fields/enumerations in terms of standard vocabularies, such as Open Concept Lab.

Electronic Health Records and Medical Imaging is therefore a useful domain in which to implement concrete <span style='color:#365450;background:#ede8ff'>DogLeash</span> components.  This does not mean that Executable Research Objects should mimic on-site <span style='color:#365450;background:#ede8ff'>EHR</span> forms used by health-care providers for their day-to-day operations; but special-purpose "research" forms may be developed that have similar presentation and terminological standards, and such forms in turn for the basis of open-access data sets.

For more details, navigate to the <span style='color:#365450;background:#ede8ff'>RedPatch</span> branch or click [here](https://github.com/scignscape/Rinc-XOA/tree/RedPatch).

---

### Publishing for Nonprofits

Supporting research in nonprofit contexts presents several distinct paradigms as compared with publishing workflows in traditional academic environments.  For one thing, authors are not necessarily affiliated with universities; they might instead be nonprofits' employees, volunteers, or independent researchers.  Outlets might not be conventional peer-reviewed journals or book series.  Some nonprofits act as their own miniature publishing houses; in other cases researchers may use platforms such as <span style='color:#365450;background:#ede8ff'>github</span>, Open Science Framework, or Dryad.  A single document publication (e.g., the <span style='color:#365450;background:#ede8ff'>PDF</span> of a research article) in this case may be just one file in a Research Object also containing source code and raw data files.

Insofar as publications are deployed with the same licences as code and data, they can be rigorously cross-referenced with sibling assets to an extent that is not feasible when documents are paywalled while data sets are not.  This use case is not well-supported by existing document-prep languages like <span style='color:#365450;background:#ede8ff'>LaTeX</span> or <span style='color:#365450;background:#ede8ff'>JATS</span>, so <span style='color:#365450;background:#ede8ff'>DogLeash</span> provides its own input markup language, machine-readable text encoding, <span style='color:#365450;background:#ede8ff'>PDF</span> annotation system, and custom <span style='color:#365450;background:#ede8ff'>PDF</span> viewers (all of which may embedded direcly in Executable Research Objects as <span style='color:#365450;background:#ede8ff'>C++</span> source files).  In this context, for example, articles are displayed via <span style='color:#365450;background:#ede8ff'>PDF</span> files that may be viewed within <span style='color:#365450;background:#ede8ff'>PDF</span> renderers built as part of the Research Object (i.e., Research Application) itself.

**_The "Diamond" Publishing Model_**

In contemporary academic publishing, the basic unit for sharing experience and ideas often is not a single manuscript, but rather a collection of files packaging variegated content-types, including <span style='color:#365450;background:#ede8ff'>PDF</span> files for viewing documents, but also machine-readable text encoding, computer code, raw data, and statistical/graphics summaries.  These packages typically adhere to collaborative standards such as Research Object Bundles, Executable Research Objects, <span style='color:#365450;background:#ede8ff'>FAIR</span>-sharing, and research-grid specifications for packages deposited on decentralized but searchable community networks.

In the genre of open-access publishing, the "diamond" model implies resources that 
are free for both readers and authors.  This paradigm is usually contrasted with a 
"gold" model where documents are free for readers but require authors to pay 
Article Processing Charges".  The diamond model is also sometimes contrasted with a "green" 
model where authors create private copies of articles whose "official" versions are 
behind a paywall.

Another important feature of most diamond systems is that authors retain all copyrights 
to their work.  They are free to share and disseminate their writing however they choose.

In traditional scientific publishing, research data sets and other supplemental 
materials are open-source while the actual books or articles are paywalled as 
commercial products.  One problem with this paradigm is that publications 
cannot be distributed alongside their complementary assets.  This means that 
cross-references between publications and other materials, such as data sets and 
computer code, cannot be rigorously defined.  Also, publications cannot benefit 
from technological integration with associated resources, via techniques 
such as customized <span style='color:#365450;background:#ede8ff'>PDF</span> viewers specifically designed for a shared data package.

In brief, the diamond model is not only more ethical; it also permits technological 
enhancements that are impossible otherwise.  In particular, it becomes possible 
to implement a rigorous interop and query infrastructure that emcompasses both text manuscripts 
and dataset file

---

### Compiler Extensions

</span>DogLeash</span> Research Objects are assumed to be <span style='color:#365450;background:#ede8ff'>C++</span> code libraries that compile to a single recognized 
Research Application (other utilities may be created as well, but someone using the data set should 
launch a single executable to access most or all available information and functionality).  In general, 
an Executable Research Object will include dataset-specific code for data deserialization, 
processing, analysis, visualization, and search capabilities.  Important procedures within this code 
should, as a rule, be exposed or wrapped in a remote-callable manner.

Assuming a Research Application is primarily implemented in <span style='color:#365450;background:#ede8ff'>C++</span>, users should have the option of 
extending or fine-tuning this code without writing their own <span style='color:#365450;background:#ede8ff'>C++</span> files that would need a separate 
compile/build step.  In short, Research Applications should have scripting capabilities.  Many 
scripting languages are possible, of course, but ideally the scripting framework should 
be compiled directly inside Research Object, rather than relying on an external 
interpreter.  Languages such as <span style='color:#365450;background:#ede8ff'>Lua</span>, <span style='color:#365450;background:#ede8ff'>AngelScript</span>, and <span style='color:#365450;background:#ede8ff'>ECL</span> (Embeddable Common Lisp) are examples 
of scripting platforms that may be distributed in source-code fashion alongside host applications.

If a more minimal scripting environment is sufficient, <span style='color:#365450;background:#ede8ff'>DogLeash</span> allows programmers to build a 
scripting framework that is tightly integrated with other components in an 
Executable Research Object.  Here is a summary of some features and techniques.

**_C++ Interop_**

The first issue is exposing <span style='color:#365450;background:#ede8ff'>C++</span> procedures/methods to the script runtime.  The point here is that 
arguments are (at first) encoded in generic containers such as <span style='color:#365450;background:#ede8ff'>QVariant</span> or <span style='color:#365450;background:#ede8ff'>QStringList</span> 
(assuming we are working in a <span style='color:#365450;background:#ede8ff'>Qt</span> environment).  We need to convert these to local 
variables that get passed on the stack (or alter the stack some other way -- <span style='color:#365450;background:#ede8ff'>AngelScript</span> actually 
employs inline assembly code).  This seems like an impasse because we do not know the arguments' 
types ahead of time.  There is a workaround, however -- even without heavy introspection and 
dependencies such as <span style='color:#365450;background:#ede8ff'>LLVM</span> -- which can be illustrated with code adopted from 
</span>rpclib</span> ([github.com/rpclib/rpclib](https://github.com/rpclib/rpclib)):


```
typedef std::function<void (QStringList)> ftype; // copy-on-write, so we don't need to pass by & const

struct Dispatcher
{
    QMap<QString, ftype> funcs;
    ...
};

template<typename T>
T qstring_to_value(QString str); // implement for quint32, etc., via QString::toUInt() and peers

template<typename F>
void wrap(Dispatcher& disp, QString name, F fn)
{
    using args_type = typename _func_traits<F>::args_type;

    disp.funcs.insert(name, [fn](QStringList args)
    {
        constexpr int args_count = std::tuple_size<args_type>::value;

        // switch for different counts; here 2, for instance
        using ty_1 = std::tuple_element_t<0, args_type>;
        using ty_2 = std::tuple_element_t<1, args_type>;
        ty_1 val_1 = qstring_to_value<ty_1>(args[0]);
        ty_2 val_2 = qstring_to_value<ty_2>(args[1]);
        fn(val_1, val_2);
    });
}
```

The point here is that we know how to wrap the exposed function at compile time because we get the argument 
count and types from `_func_traits<>` and `tuple_size<>`.  Every procedure thereby gets a conventient 
wrapper all of which have the same type (here using <span style='color:#365450;background:#ede8ff'>QStringList</span>).  There's a little more work 
to do, particularly to handle return values (plus maybe exceptions and pointer-to-members), but this is the basic idea.

We need a different technique for dynamically loaded libraries, however, because in that case we 
*don't* have signatures at compile time, so no `_func_traits` or `tuple_element`.  However, we 
can handle many or most functions that might be exposed for a data set.  Typically these 
fit familiar patterns that can be summarized with a compact code.  For instance, use numbers 
like 1, 2, 4, 8 for integers of different sizes.  Then a pair of 4-byte arguments with no return 
could get a code like <span style='color:#365450;background:#ede8ff'>440</span>, and a wrapper constructured for every procedure with that kind of 
signature (or anything binary compatible to it), rather than one-wrapper-per-function as above:

```
void call_440(fn_type fn, QStringList args)
{
 quint32 arg1 = args[0].toUInt();
 quint32 arg2 = args[1].toUInt();
 fn(arg1, arg2);
}
```

A slew of wrappers in the form call_XXX could be produced via code generators, and dispatchers 
selected via a string of <span style='color:#365450;background:#ede8ff'>switch</span> statements: one for the arg count, next for the arg1 type 
(e.g., 1, 2, 4, or 8), next the arg2 type, etc.  Those <span style='color:#365450;background:#ede8ff'>switch</span>es would work off of digits in 
the signture "code" (like 440) so that registering even an <span style='color:#365450;background:#ede8ff'>.so</span> runtime procedure 
would take only a single numeric code (which is simpler than how registering works 
in <span style='color:#365450;background:#ede8ff'>ECL</span> or <span style='color:#365450;background:#ede8ff'>AngelScript</span>).


**_Signature Codes_**

The problem with this technique is that only a relatively limited set of signatures can be 
supported -- a compilation unit can have only so many <span style='color:#365450;background:#ede8ff'>switch</span> cases.  <span style='color:#365450;background:#ede8ff'>DogLeash</span> tries 
to extend the range of available procedures by employing a more indirect signature-code 
mechanism.  Note that the count of signature patterns is affected by the number 
of distinct types a function takes as parameters.  For instance, if all arguments have 
the same type, then the only thing that varies is the number of parameters, so there's a 
maximum of say 10 <span style='color:#365450;background:#ede8ff'>switch</span> cases (<span style='color:#365450;background:#ede8ff'>Qt</span>'s meta-object system, for <span style='color:#365450;background:#ede8ff'>QObject</span> subclasses, 
recognizes up to 10 arguments).  If there are two types, then a variety of argpack-sizes 
can be covered by bit vectors (on for one type and off for the other).  It's only with three 
or more types that you get potentially complex dispatch trees, but you're also problably 
not going to get a lot of *repetition*.  Suppose you have exactly three arguments of 
three different types: each signature is then a permutation of three elements, of which 
there are only six, plus <span style='color:#365450;background:#ede8ff'>switch</span> cases for the types involved.

By "types" here I mean any collection of binary-compatible types: we can cast a function-pointer 
to a generic signature based on unsigned integers, for example.  The actual procedures 
might take signed integers instead, or <span style='color:#365450;background:#ede8ff'>enum</span> values, but can be correctly called via 
that partially-type-erased pointer instead.  In any case, <span style='color:#365450;background:#ede8ff'>RedPatch</span> has 
sample code representing dispatch-tables sufficient for most signatures one might 
need to expose from a library.

**_Language Server Protocol_**

The <span style='color:#365450;background:#ede8ff'>Language Server Protocol</span> (<span style='color:#365450;background:#ede8ff'>LSP</span>), developed by Microsoft, is a tool through which 
code editors and Integrated Development Environments (<span style='color:#365450;background:#ede8ff'>IDE</span>s) communicate 
with external programs that play the role of code assistants, 
offering hints, information on data types and function signatures, code completion 
suggestion, etc.  For example, <span style='color:#365450;background:#ede8ff'>Clangd</span> is the preeminent Language Server 
for <span style='color:#365450;background:#ede8ff'>C++</span>.

The <span style='color:#365450;background:#ede8ff'>LSP</span> model is flexible, and a variety of different software components 
can be useful Language Servers.  It is not necessary to fully parse 
source files, as <span style='color:#365450;background:#ede8ff'>Clangd</span> does; depending on the language and the server 
it may be possible to build more limited views onto source code 
which still can be helpful for certain <span style='color:#365450;background:#ede8ff'>LSP</span> requests.  Language 
Servers may also, in principle, be tailored to narrower project-areas 
rather than any code that happens to be written in a given 
language.  For example, biomedical source code that recognizes 
Open Concept Lab and similar standard terminologies can serve 
information about procedures, object, and types map to concept 
identifiers.  Instead of reading this information from source code 
directly they could rely on metadata files instead.

In short, a domain-specific Language Server can be built via 
metadata files that accompany source code and provide information 
in a variety of contexts, including code-introspection and dynamic 
dispatch.  Continuing the above <span style='color:#365450;background:#ede8ff'>RPC</span> example, functions' 
names and signature codes are the kind of information that could be 
exposed via metadata files.

By way of illustration, the following is an example of how 
to use <span style='color:#365450;background:#ede8ff'>LLVM</span> <span style='color:#365450;background:#ede8ff'>IRBuilder</span> code, generated by Google <span style='color:#365450;background:#ede8ff'>AI</span>:

```
Type *Int32Ty = Type::getInt32Ty(Context);
std::vector<Type*> ParamTypes = {Int32Ty, Int32Ty};
FunctionType *FuncType = FunctionType::get(Int32Ty, ParamTypes, false);
Function *AddFunc = Function::Create(FuncType, Function::ExternalLinkage, "add", OwnerModule.get());

Function::arg_iterator Args = AddFunc->arg_begin();
Value *ArgA = Args++;
ArgA->setName("a");
Value *ArgB = Args;
ArgB->setName("b");
```

But this is quite similar to how we would populate a function-call at runtime, to be passed 
to one of the dispatch protocols outlined above.  Let's imagine wrapping the <span style='color:#365450;background:#ede8ff'>IRBuilder</span> 
code in a sort of Virtual Machine:

```
 init-arg-list
 add-param-type Int32Ty
 add-param-type Int32Ty
 return-type Int32Ty
 reset-arg-cursor
 set-arg-name "a"
 set-arg-name "b"
 set-proc-name "add"
 write-function-signature
```

With very few changes (maybe the last line becomes some sort of <span style='color:#365450;background:#ede8ff'>call</span> instruction instead) this might be 
almost identical to VM instructions for an <span style='color:#365450;background:#ede8ff'>FFI</span>-style call intead.

The point is that a standardized type-metadata format could be used simultaneously both to 
feed information to Language Servers and to enable Script Hosting (and, by 
extension, query evaluation).  That's the rationale behind <span style='color:#365450;background:#ede8ff'>DogLeash</span> as a Language Server 
*and* Script Host (the "leash") and the basis for the <span style='color:#365450;background:#ede8ff'>Qynviper</span> 
modules mentioned above.

<a id="sample-documents-raised"></a>

## Sample Documents

The following are examples of my own publications (not in chronological order) 
developed with <span style='color:#365450;background:#ede8ff'>DogLeash</span> code in some iteration.

- [Ordering Conceptual Synthesis: The Implications of Cognitive Phenomenology for Syntactic Theory](https://scignscape.github.io/Rinc-XOA/authors/NathanielChristen/OrderingConceptualSynthesis.pdf)  Unpublished, by intent, 
to serve as a demo for certain document-generation features.

- [Merging Full-Text Query with Research Data Sets: A perspective from compiler theory](https://scignscape.github.io/Rinc-XOA/documents/A-perspective-from-compiler-theory.pdf)  Presented at NISO/JATS 2026.

- [Ordering Conceptual Synthesis: The Implications of Cognitive Phenomenology
for Syntactic Theory](https://scignscape.github.io/Rinc-XOA/documents/Ordering-Conceptual-Synthesis.pdf)  A paper about linguistics and the philosophy of science, which uses 
programming languages as case-studies for some 
linguistic topics.  The Executable Research Object code 
for this manuscript included document-specific 
algorithms to isolate linguistic samples and present 
them alongside the index as a kind of thematic summary.

- "From 'Naturalizing Phenomenology' to Formalizing 
Cognitive Linguistics (I-III)"  These three papers were 
developed in connection with supplemental materials 
for an article in the International Journal of 
Speech Technology, where I joined as a co-author 
with researchers from Bar-Ilan University (Israel) 
and Johns Hopkins (US).  The supplemental content 
was a data set including audio and written 
samples for linguistic annotation, including some 
taken as "hypothetical" sentences or fragments 
created to illustrate linguistic themes or 
theories.  I wrote three supplemental essays to analyze 
material present in the data set.  Within those 
papers, I notated new or previously-discussed 
linguistic samples, and employed <span style='color:#365450;background:#ede8ff'>DogLeash</span> to 
pull those examples as structured data available 
to readers as part of the dataset package; in short, 
the code demonstrated techniques for compiling 
linguistic data sets from example 
sentences/fragments listed for analysis in linguistics papers.

    1.  [From 'Naturalizing Phenomenology' to Formalizing Cognitive Linguistics (I):
Cognitive Transform Grammar](https://scignscape.github.io/Rinc-XOA/documents/ijst/ctg.pdf)

    2.  [From 'Naturalizing Phenomenology' to Formalizing Cognitive Linguistics (II):
Grounding and Center/Peripheral Relations](https://scignscape.github.io/Rinc-XOA/documents/ijst/icg.pdf)

    3.  [From 'Naturalizing Phenomenology' to Formalizing Cognitive Linguistics (III):
Externalism and the Interface Theory of Meaning](https://scignscape.github.io/Rinc-XOA/documents/ijst/itm.pdf)

- The chapters of the book _Innovative Data Integration and Conceptual Space Modeling 
for COVID, Cancer, and Cardiac Care_ (Elsevier, 2022).  These are individual chapters' penultimate versions, 
not identical to the printed book.

  1.  [Chapter 1 -- Introduction](https://scignscape.github.io/Rinc-XOA/documents/data-integration/Chapter1.pdf)
  2.  [Chapter 2 -- Data Structures Associated with Biomedical Research](https://scignscape.github.io/Rinc-XOA/documents/data-integration/Chapter2.pdf)
  3.  [Chapter 3 -- Data Mining and Predictive Analytics for Cancer and COVID-19](https://scignscape.github.io/Rinc-XOA/documents/data-integration/Chapter3.pdf)
  4.  [Chapter 4 -- Modular Design, Image Biomarkers, and Radiomics](https://scignscape.github.io/Rinc-XOA/documents/data-integration/Chapter4.pdf)
  5.  [Chapter 5 -- Types’ Internal Structure and ‘Nonconstructive’ (‘NC4’) Type Theory](https://scignscape.github.io/Rinc-XOA/documents/data-integration/Chapter5.pdf)
  6.  [Chapter 6 -- Using Code Models to Instantiate Data Models](https://scignscape.github.io/Rinc-XOA/documents/data-integration/Chapter6.pdf)
  7.  [Chapter 7 -- Multi-Aspect Modules and Image Annotation](https://scignscape.github.io/Rinc-XOA/documents/data-integration/Chapter7.pdf)
  8.  [Chapter 8 -- Image Annotation as a Multi-Aspect Case-Study](https://scignscape.github.io/Rinc-XOA/documents/data-integration/Chapter8.pdf)
  9.  [Chapter 9 -- Conceptual Spaces and Scientific Data Models](https://scignscape.github.io/Rinc-XOA/documents/data-integration/Chapter9.pdf)

- Five chapters from the book _AI, IoT, Big Data and Cloud Computing for Industry 4.0_ 
(Amy Neustein, Parikshit N. Mahalle, Prachi Joshi, Gitanjali Rahul Shinde, eds., 
Springer 2024: [https://link.springer.com/book/10.1007/978-3-031-29713-7](https://link.springer.com/book/10.1007/978-3-031-29713-7)).

    1.  [Chapter 20 -- Multi-Component Interoperability and Virtual Machines: Examples from
Architecture, Engineering, Cyber-Physical Networks, and Geographic Information Systems](https://scignscape.github.io/Rinc-XOA/documents/iot/ch20.pdf)

    2.  [Chapter 21 -- Virtual Machines and Hypergraph Data/Code Models: Graph-Theoretic
Representations of Lambda-Style Calculi](https://scignscape.github.io/Rinc-XOA/documents/iot/ch21.pdf)

    3.  [Chapter 22 -- GUI Integration and Virtual Machine Constructions for Image Processing:
Phenomenological and Database-Engineering insights into Computer Vision](https://scignscape.github.io/Rinc-XOA/documents/iot/ch22.pdf)

    4.  [Chapter 23 -- The Missing Links Between Computer and Human Languages: Animal Cognition
and Robotics](https://scignscape.github.io/Rinc-XOA/documents/iot/ch23.pdf)

    5.  [Chapter 24 -- GUIs, Robots, and Language: Toward a Neo-Davidsonian Procedural Semantics](https://scignscape.github.io/Rinc-XOA/documents/iot/ch24.pdf)


- My doctoral dissertation on ["Phenomenological Reductionism"](https://scignscape.github.io/Rinc-XOA/documents/nc/dissertation.pdf).  This document has fairly basic layout, but I still stand by the content.


---


# Other Projects and Documents Using DogLeash

Due to privacy or copyright issues, for some of these examples 
I can only describe projects and their unique coding 
requirements.  In other cases this list will include 
links to <span style='color:#365450;background:#ede8ff'>PDF</span> documents illustrating some <span style='color:#365450;background:#ede8ff'>DogLeash</span> features.

###  Projects Involving Data and/or Code Packages

1.  CSV and SVG Integration:  This project coincided with the five-year cycle 
for the Environmental Protection Agency's "Hazard Mitigation" plan.  As part 
of this <span style='color:#365450;background:#ede8ff'>EPA</span> program, states and counties are required to submit documentation 
for how they identify and address environmental dangers in their 
communities.  Here, I used <span style='color:#365450;background:#ede8ff'>DogLeash</span> tools to address both environmental 
data and Zoning/Land Use ordinances so as to explore the connections 
between environmental health and urban development.  Part of this 
project involved extending a New York City tool called 
</span>ZoLa</span> (for Zoning and Land Use), which was created by 
NYC Planning Labs but openly shared in the hopes that 
other jurisdictions adopt the same technology.  Other 
data sourecs came from the <span style='color:#365450;background:#ede8ff'>EPA</span> "Toxic Release Inventory" (<span style='color:#365450;background:#ede8ff'>TRI</span>) 
data set, which publishes data files identifying reported 
contamination incidents by geographic coordinates, and 
has been studied for publications such as the NYC "Environmental Justice" 
(<span style='color:#365450;background:#ede8ff'>EJNYC</span>) report and mapping tool.  My goal was to examine how 
data sets such as <span style='color:#365450;background:#ede8ff'>TRI</span>, along with environmental-impact 
data presented by states or private organizations, could be cross-referenced 
with Zoning and Land Use maps.  Demonstration code included <span style='color:#365450;background:#ede8ff'>CSV</span> deserializers 
to handle to complex <span style='color:#365450;background:#ede8ff'>TRI</span> data structures, that were hierarchical 
more than tabular in nature but used <span style='color:#365450;background:#ede8ff'>CSV</span> as a rough serialization tool, 
as well as native-compiled <span style='color:#365450;background:#ede8ff'>GUI</span> components based on <span style='color:#365450;background:#ede8ff'>OpenStreetMap</span> 
for <span style='color:#365450;background:#ede8ff'>GIS</span> displays.

    During this work I identified a series of errors with the <span style='color:#365450;background:#ede8ff'>TRI</span> encoding and 
documentation, so another layor of components implemented for this project 
involved mapping <span style='color:#365450;background:#ede8ff'>TRI</span>-related <span style='color:#365450;background:#ede8ff'>PDF</span> files to <span style='color:#365450;background:#ede8ff'>SVG</span>, so that I could 
superimpose annotations identifying the <span style='color:#365450;background:#ede8ff'>TRI</span> problems and 
how they could be corrected in code. 


2.  Annotated Legal Documents:  This was another project leveraging 
</span>PDF</span>-to-</span>SVG</span> conversion.  The basic material for this project 
was a collection of legal documents that had been merged into a 
single file and then annotated to show patterns of 
behavior.  Applying techniques from ethnomethodology, the annotator 
designed a controlled vocabuly to insert terms functioning 
as "handles" into <span style='color:#365450;background:#ede8ff'>PDF</span> comment boxes.  I then implemented 
code which scanned these <span style='color:#365450;background:#ede8ff'>PDF</span> annotations and identified 
sub-documents which, according to the annotator, 
exhibited various patterns of communicative behavior.  I then 
split the larger <span style='color:#365450;background:#ede8ff'>PDF</span> into multiple subdocuments and mapped 
that content to hybrid <span style='color:#365450;background:#ede8ff'>HTML</span>/</span>SVG</span> pages, together with an 
online index that showed annotated classifications for 
each subdocument, plus page-by-page as well as document-by-document 
navigation for the linked pages.  The overall package was presented 
to a judge as a user-friendly alternative to submitting the 
original manuscript as a monolithic item of evidence. 

3.  Building a Book's Second Edition:  This project involved merging 
additional material added by the authors into a book they had 
initially published in 2005.  We built an in-house full <span style='color:#365450;background:#ede8ff'>PDF</span> 
of the new edition that mimicked the style and layout of the 
preparatory manuscripts shared by the publishers.  By cross-referencing 
the two versions, we were able to identify errors made on the 
publisher's end by copy editors and also fine-tune the new material.
Significant effort went into creating and updated index.  Special 
</span>DogLeash</span> tools laid a foundation for custom <span style='color:#365450;background:#ede8ff'>GUI</span>s whose goal 
was to compare the first- and second-edition manuscripts to 
ensure that all previous index entries were migrated to the 
updated book, as well as creating new index material in the 
pbulisher's desired metadata format.

4.  Examining Biomedical Software:  During the Covid pandemic, 
I wrote the text for a book called _Innovative Data Integration and Conceptual 
Space Modeling for COVID, Cancer, and Cardiac Care_ (Elsevier, 
2022).  This book included a detailed examination of certain 
software components — such as the Cancer Phenomics Toolkit (<span style='color:#365450;background:#ede8ff'>CapTk</span>), 
</span>IQmol</span> molecular visualization software, <span style='color:#365450;background:#ede8ff'>cytolib</span> for flow cytometry, 
</span>medInria</span> and <span style='color:#365450;background:#ede8ff'>Semantic PACS</span> (Picture Archiving and Communication System), 
and the Cancer Bioinformatics Grid (<span style='color:#365450;background:#ede8ff'>caBig</span>) Image Annotation Toolkit — 
bioinformatics file formats (and their deserialization/analytic libaries), 
and collaborative projects (such as <span style='color:#365450;background:#ede8ff'>caBig</span>'s "Digital Model Repository" 
and the <span style='color:#365450;background:#ede8ff'>CORD-19</span> archive for Covid research).  <span style='color:#365450;background:#ede8ff'>CORD-19</span> (the 
COVID-19 Open Research Dataset) grew to encompass over 400,000 open-access 
articles focusing on SARS-COV-2 and related topics (including the original 
SARS epidemic and Coronavirus biology in general) with freely-available 
full-text encoding.  The goal of <span style='color:#365450;background:#ede8ff'>CORD-19</span> was to help scientists in 
different areas addressing the pandemic (viral morphology, infectious 
mechanisms, diagnostics, clinical treatment assesment, vaccine development, 
genomics, variants/mutations, epidemiology, long-term effects) discover 
resources or research that could augment their own work, helping 
piece together the Covid puzzle.  Unfortunately, much of <span style='color:#365450;background:#ede8ff'>CORD-19</span>'s
implementation depended on <span style='color:#365450;background:#ede8ff'>PDF</span> text extraction, which 
yielded errors and limitations I analyzed in the Elsevier book.
The <span style='color:#365450;background:#ede8ff'>CORD-19</span> curators (from Allen Institute for AI) were open about these problems and 
even issued a "call to action" requesting publishers to 
develop and adopt more rigorous text-encoding 
methods:

    >   Though the full text of many scientific papers are available to researchers through <span style='color:#365450;background:#ede8ff'>CORD-19</span>, a number of challenges prevent easy application of <span style='color:#365450;background:#ede8ff'>NLP</span> and text mining techniques to these papers. First, the primary distribution format of scientific papers — <span style='color:#365450;background:#ede8ff'>PDF</span> — is not amenable to text processing. The PDF file format is designed to share electronic documents rendered faithfully for reading and printing, and mixes visual with semantic information. Significant effort is needed to coerce <span style='color:#365450;background:#ede8ff'>PDF</span> into a format more amenable to text mining, such as <span style='color:#365450;background:#ede8ff'>JATS</span> <span style='color:#365450;background:#ede8ff'>XML</span>, <span style='color:#365450;background:#ede8ff'>BioC</span>, ... or <span style='color:#365450;background:#ede8ff'>S2ORC</span> <span style='color:#365450;background:#ede8ff'>JSON</span> ... [W]e can still benefit from better <span style='color:#365450;background:#ede8ff'>PDF</span> parsing tools for scientific documents. As a complement, scientific papers should also be made available in a structured format like <span style='color:#365450;background:#ede8ff'>JSON</span>, <span style='color:#365450;background:#ede8ff'>XML</span>, or <span style='color:#365450;background:#ede8ff'>HTML</span>.

    Hopefully <span style='color:#365450;background:#ede8ff'>DogLeash</span> can contribute to this initiative. 

    Apart from text representations responding to the Allen Institute 
"call to action", the special code for this book involved 
compiling and, in some cases, extending bioinformatics 
or scientific software applicable to biomedical 
research.  One of the book's themes was how to implement data-integration 
protocols that could unify disparate applications into 
executable research collaborations.  Much of the book's discussion 
was shaped by prototypes for plugins or extensions 
to software commonly used for research or lab services 
in fields such as organic chemistry, tumor simulations, 
systems biology, bioimaging, and Computer Vision.












