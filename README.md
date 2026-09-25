
# Rinc-XOA : Research in nonprofit contexts - Executable Open Access

If you are interested particularly in the $\color{#a65450}\mathrm{RedPatch}$ Community Health research platform, 
that's detailed in this repository's $\color{#a65450}\mathrm{RedPatch}$ branch or [skip ahead](#red-patch).

For a description of several projects that employed some of the code published here, 
including a list of open-access articles and book chapters, scroll down or [skip ahead](#sample-documents-raised).

Many of these components are built around a new Virtual Machine generator called 
$\underline{\color{#3e2a47}\mathrm{\small{}Qynviper}}$; for details on that, scroll down or [skip ahead](#qynviper).

***Very brief personal bio*** &nbsp;&#x2aa2;&nbsp; I (Nathaniel Christen) hold a BA in Computer Science from Bard College (Annandale-on-Hudson, NY) and MA in Linguistics from George Mason University (Fairfax, VA). My doctoral research involved Cognitive Grammar, Phenomenology, and Philosophy of Science (I&rsquo;ve even linked the final draft of my dissertation below, though it's presumably been almost 20 years since anyone looked at it).

---

### Overview

In publishing, Diamond $\color{black}\textbf{(}\color{#a65450}\mathrm{DiamondOA}\color{black}\textbf{)}$ is the most complete Open Access model, with no fees either for authors (i.e., Article Processing Charges 
$\color{black}\textbf{(}\color{#a65450}\mathrm{APC}\color{black}\textsf{s}\textbf{)}$) or readers (i.e., article paywalls).  The work needed to prepare manuscripts for publication is either performed on a volunteer basis or supported by &ldquo;Diamond Open Access Funds&rdquo;, 
which are more prevalent in the European Union than the United State.

Meanwhile, Executable Research Objects
$\color{black}\textbf{(}\color{#a65450}\mathrm{ERO}\color{black}\textsf{s}\textbf{)}$
are one form of Research Object/data set guided by data transparency and $\color{#a65450}\mathrm{FAIR}$-sharing (Findable, Accessible, Interoperable, Reusable) principles.  Research Objects in general may include multiple forms of digital assets (text, code, raw data files, and perhaps multimedia content) which can present challenges for in-depth usage.  An *Executable* Research Object in particular provides a single Research Application that serves as an entry point or overarching resource streamlining access to the variegated parts of a data publication.  In general, these Research Applications are standalone desktop-style programs which, when launched, will provide visual summaries and windows to manage data set records, as well as viewers for other media types (e.g., $\color{#a65450}\mathrm{PDF}$ documents, images, videos, digital maps, etc.).

For the current repository and siblings, Executable Open Access
$\color{black}\textbf{(}\color{#a65450}\mathrm{XOA}\color{black}\textbf{)}$ designates a synthesis of these two paradigms.  Most $\color{#a65450}\mathrm{FAIR}$-sharing projects, to be sure, are Open Access by default because they are hosted on free services such as Open Science Framework 
$\color{black}\textbf{(}\color{#a65450}\mathrm{OSF}\color{black}\textbf{)}$, Zenodo, 
or Dryad &mdash; often linked to publications via &ldquo;Data Availability&rdquo; or &ldquo;Supplemental Materials&rdquo; sections on articles&rsquo; landing pages (which also have abstracts, bibliographies, and so forth).  There is no such thing as a &ldquo;dataset processing charge&rdquo;.  Nonetheless,
$\color{#a65450}\mathrm{ERO}\color{black}\textsf{s}$ are most productive when they include complete version of associated research articles &mdash; both in human-readable (e.g., $\color{#a65450}\mathrm{PDF}$) and machine-readable (e.g., $\color{#a65450}\mathrm{JATS}$
$\color{#a65450}\mathrm{XML}$) formats, which requires that the entire package be governed by a
$\color{#a65450}\mathrm{DiamondOA}$ licence.  Moreover, aggregating disparate dataset materials into an overarching Research Application requires additional programming that could potentially be supported by
$\color{#a65450}\mathrm{DiamondOA}$ funds or similar initiatives.  In short, the $\color{#a65450}\mathrm{ERO}$ and 
$\color{#a65450}\mathrm{DiamondOA}$ paradigms are sufficiently interrelated/overlapping that each may help promote the other.

$\underline{\color{#3e2a47}\mathrm{\small{}Rinc}\text{-}\mathrm{\small{}XOA}}$ 
(this repository) has a sibling repo called
$\underline{\color{#3e2a47}\mathrm{\small{}DogLeash}}$
(Diamond Object Grid - Language Server and Script Host), at [github.com/ScignScape/DogLeash](https://github.com/scignscape/DogLeash/) which holds most of the actual code.  This code base is intended to provide tools and templates for Executable Research Objects.  $\color{#a65450}\mathrm{DogLeash}$ provides several &ldquo;modules&rdquo; for specific subject areas and implementation requirements, such as Medical Imaging, Geographic Information Systems, and Compiler Extensions.  A $\color{#a65450}\mathrm{Rinc}\text{-}\mathrm{XOA}$ project can include any modules relevant to its topic.

---

<a id="qynviper"></a>

## Qynviper Modules

A $\color{#a65450}\mathrm{Qynviper}$ $\color{#a65450}\mathrm{VM}$ &mdash; &ldquo;query/native interop compiler&rdquo; &mdash; can be implemented via code published in $\color{#a65450}\mathrm{RedPatch}$.  The idea 
behind $\color{#a65450}\mathrm{Qynviper}$ is that opcodes delegate to methods in $\color{#a65450}\text{C}\large{}\text{++}$ classes (or potentially those of other languages).  Each such class is called a &ldquo;module&rdquo;.  By selecting a group of modules, individual
$\color{#a65450}\mathrm{VM}\color{black}\textsf{s}\textbf{)}$
can target capabilities to their use-cases.  For example, a
$\color{#a65450}\mathrm{VM}$ may be engineered as a compilation target for imperative/procedure scripting languages &mdash; with support for lexical scopes, variables, function calls, and so forth &mdash; but in other use-cases &mdash; e.g., object deserialization &mdash; $\color{#a65450}\mathrm{VM}$ blocks are generated from $\color{#a65450}\mathrm{XML}$ or $\color{#a65450}\mathrm{JSON}$ sources which are declarative rather than imperative.  A conventional $\color{#a65450}\text{C}\large{}\text{++}$ $\color{#a65450}\mathrm{SAX}$ parser responds immediately to $\color{#a65450}\mathrm{XML}$ parsing events, thereby conflating $\color{#a65450}\mathrm{DTD}$ and handler logic, whereas a
$\color{#a65450}\mathrm{VM}$ can partition the problem into two almost entirely separate domains (generating 
$\color{#a65450}\mathrm{VM}$ instruction sequences versus implementing opcode handlers).  The 
$\color{#a65450}\mathrm{Qynviper}$ components make heavy use of preprocessor macros, and in general it takes just a few minutes to rig up $\color{#a65450}\text{C}\large{}\text{++}$ classes as modules once the actual opcode methods are implemented.

The $\color{#a65450}\mathrm{RedPatch}$ sources (outlined next) are built 
around several VMs created in this manner, partly for demonstration purposes.  This includes document processors for publications &mdash; see the sample &ldquo;Ordering Concepual Synthesis&rdquo; paper linked below, or 
[here](https://scignscape.github.io/Rinc-XOA/authors/NathanielChristen/OrderingConceptualSynthesis.pdf).  The paper provides links to five other representations targeting different text-encoding specifications, such as $\color{#a65450}\mathrm{RO}\text{-}\mathrm{Crate}$ and $\color{#a65450}\mathrm{TAGML}$ (Text-As-Graph Markup Language).  Here, these are not markup formats directly (though when needed convertable to/from $\color{#a65450}\mathrm{XML}$ or $\color{#a65450}\mathrm{JSON}\text{)}$ but rather
$\color{#a65450}\mathrm{Qynviper}$ code used at different points in a publishing workflow.

**_AMPATH Forms_**

In addition to document preparation, $\color{#a65450}\mathrm{RedPatch}$ illustrates other VM examples for use-cases such as object deserialization.  For instance, one
$\color{#a65450}\mathrm{Qynviper}$ module is built around $\color{#a65450}\mathrm{AMPATH}$ &mdash; the &ldquo;Academic Model Providing Access To Healthcare&rdquo; &mdash; which sponsors Electronic Health Record software used by
$\color{#a65450}\mathrm{NGO}\color{black}\textsf{s}$
such as Doctors Without Borders and Partners in Health.  Although eventually rendered as $\color{#a65450}\mathrm{HTML}$ (via $\color{#a65450}\mathrm{ReactJS}$) these records are intrinsically defined as $\color{#a65450}\mathrm{JSON}$ configuration files, which opens the possibility for generating alternative front-end viewers.  The $\color{#a65450}\mathrm{RedPatch}$ branch shows an example where $\color{#a65450}\mathrm{AMPATH}$ forms are translated to 
$\color{#a65450}\text{C}\large{}\text{++}$ $\color{#a65450}\mathrm{Qt}$ classes and compiled as ordinary desktop libraries (or standalone applications).  Such a &ldquo;native rendering engine&rdquo; is potentially useful in providing an $\color{#a65450}\mathrm{EHR}$ framework which does not depend on $\color{#a65450}\mathrm{HTTP}$ servers and client/server networking, and it also shows how $\color{#a65450}\mathrm{AMPATH}$ annotations (with sources such as Open Concept Lab and other biomedical controlled vocabularies) can augment the searchability and interoperability of $\color{#a65450}\text{C}\large{}\text{++}$ $\color{#a65450}\mathrm{GUI}$ components.  The role for
$\color{#a65450}\mathrm{Qynviper}$ here is to generate $\color{#a65450}\text{C}\large{}\text{++}$ code: $\color{#a65450}\mathrm{AMPATH}$ configuration files are first parsed into 
$\color{#a65450}\mathrm{VM}$
scripts which are separately executed to create the final $\color{#a65450}\mathrm{GUI}$ code.

**_DCMTK_**

Another similar example, based on $\color{#a65450}\mathrm{XML}$ rather than $\color{#a65450}\mathrm{JSON}$, provides an extension to the widely-used $\color{#a65450}\mathrm{DCMTK}$ library for working with $\color{#a65450}\mathrm{DICOM}$ (Digital Imaging and Communications in Medicine) series.  This library offers multiple utilities for converting $\color{#a65450}\mathrm{DICOM}$ files to other image and data formats $\text{(}\color{#a65450}\mathrm{XML}$, $\color{#a65450}\mathrm{HTML}$, $\color{#a65450}\mathrm{JPEG}$ and so forth) but currently lacks support for other diagnostic-imaging formats, such as $\color{#a65450}\mathrm{MI}\text{-}\mathrm{CDM}$ (Medical Imaging Common Data Model), 
part of the $\color{#a65450}\mathrm{OMOP}\text{-}\mathrm{CDM}$ (Observational Medical Outcomes Partnership) Common Data Model.  For publishing medical-imaging research (topics such as AI Segmentation and Neuroimaging) it would also be helpful to map $\color{#a65450}\mathrm{DSR}$ (Structured Reporting) observations, annotations, and &ldquo;key&rdquo; images onto common Open Science formats such as $\color{#a65450}\mathrm{RO}\text{-}\mathrm{Crate}$.  For these use-cases, $\color{#a65450}\mathrm{RedPatch}$ provides a $\color{#a65450}\mathrm{Qynviper}$ $\color{#a65450}\mathrm{VM}$ whose purpose is to parse $\color{#a65450}\mathrm{dcm2xml}$ and $\color{#a65450}\mathrm{dsr2xml}$ output and dispatch calls to code-generators for formats not currently supported by $\color{#a65450}\mathrm{DCMTK}$.

As a mostly self-contained platform, $\color{#a65450}\mathrm{Qynviper}$
$\color{#a65450}\mathrm{VM}\color{black}\textsf{s}$ can readily be embedded in host applications, such as $\color{#a65450}\mathrm{3DSlicer}$ (the preeminent research tool for medical imaging and $\color{#a65450}\mathrm{DICOM}$ series).

---

<a id="red-patch"></a>

## Community Health Research Platform


I have grouped most of the $\color{#a65450}\mathrm{\large DogLeash}$ modules into <span style='color:red!10!blue;background:#ede8ff'>RedPatch}$ (Research Objects - Diamond Open Access Targeting Children's and Community Health) which has its own branch in the current repository.  This code base leverages similarities between Electronic Health Records and Executable Research Object &ldquo;microcomponents&rdquo;.  More specifically, at least for $\color{#a65450}\mathrm{DogLeash}$ an Executable Research Object is composed of multiple microcomponents which, in general, each provide one application window and present the user with information and/or graphics from a particular data profile, multimedia resource, or record source (data base, data set, 
$\color{#a65450}\mathrm{CSV}\color{black}/\color{#a65450}\mathrm{XML}\color{black}/\color{#a65450}\mathrm{JSON}$ file, etc.).  A good example of microcomponents would be displays showing a specific type of $\color{#a65450}\mathrm{EHR}$ form, or a single medical image alongside provenance, diagnostic, and annotation metadata.  In $\color{#a65450}\mathrm{DogLeash}$, for each microcomponent there is typically a single $\color{#a65450}\text{C}\large{}\text{++}$ class encapsulating the totality of information provided by one instance of the component, plus metadata about valid ranges/values for form fields and annotations on fields/enumerations in terms of standard vocabularies, such as Open Concept Lab.

Electronic Health Records and Medical Imaging is therefore a useful domain in which to implement concrete $\color{#a65450}\mathrm{DogLeash}$ components.  This does not mean that Executable Research Objects should mimic on-site $\color{#a65450}\mathrm{EHR}$ forms used by health-care providers for their day-to-day operations; but special-purpose &ldquo;research&rdquo; forms may be developed that have similar presentation and terminological standards, and such forms in turn for the basis of open-access data sets.

For more details, navigate to the $\color{#a65450}\mathrm{RedPatch}$ branch or click [here](https://github.com/scignscape/Rinc-XOA/tree/RedPatch).

---

## Publishing for Nonprofits

Supporting research in nonprofit contexts presents several distinct paradigms as compared with publishing workflows in traditional academic environments.  For one thing, authors are not necessarily affiliated with universities; they might instead be nonprofits&rsquo; employees, volunteers, or independent researchers.  Outlets might not be conventional peer-reviewed journals or book series.  Some nonprofits act as their own miniature publishing houses; in other cases researchers may use platforms such as $\color{#a65450}\mathrm{github}$, Open Science Framework, or Dryad.  A single document publication (e.g., the $\color{#a65450}\mathrm{PDF}$ of a research article) in this case may be just one file in a Research Object also containing source code and raw data files.

Insofar as publications are deployed with the same licences as code and data, they can be rigorously cross-referenced with sibling assets to an extent that is not feasible when documents are paywalled while data sets are not.  This use case is not well-supported by existing document-prep languages like $\color{#a65450}\mathrm{LaTeX}$ or $\color{#a65450}\mathrm{JATS}$, so $\color{#a65450}\mathrm{DogLeash}$ provides its own input markup language, machine-readable text encoding, $\color{#a65450}\mathrm{PDF}$ annotation system, and custom $\color{#a65450}\mathrm{PDF}$ viewers (all of which may embedded direcly in Executable Research Objects as $\color{#a65450}\text{C}\large{}\text{++}$ source files).  In this context, for example, articles are displayed via $\color{#a65450}\mathrm{PDF}$ files that may be viewed within $\color{#a65450}\mathrm{PDF}$ renderers built as part of the Research Object (i.e., Research Application) itself.

**_The &ldquo;Diamond&rdquo; Publishing Model_**

In contemporary academic publishing, the basic unit for sharing experience and ideas often is not a single manuscript, but rather a collection of files packaging variegated content-types, including $\color{#a65450}\mathrm{PDF}$ files for viewing documents, but also machine-readable text encoding, computer code, raw data, and statistical/graphics summaries.  These packages typically adhere to collaborative standards such as Research Object Bundles, Executable Research Objects, $\color{#a65450}\mathrm{FAIR}$-sharing, and research-grid specifications for packages deposited on decentralized but searchable community networks.

In the genre of open-access publishing, the &ldquo;diamond&rdquo; model implies resources that 
are free for both readers and authors.  This paradigm is usually contrasted with a 
&ldquo;gold&rdquo; model where documents are free for readers but require authors to pay 
processing charges.  The diamond model is also sometimes contrasted with a &ldquo;green&rdquo; 
model where authors create private copies of articles whose &ldquo;official&rdquo; versions are 
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
such as customized $\color{#a65450}\mathrm{PDF}$ viewers specifically designed for a shared data package.

In brief, the diamond model is not only more ethical; it also permits technological 
enhancements that are impossible otherwise.  In particular, it becomes possible 
to implement a rigorous interop and query infrastructure that emcompasses both text manuscripts 
and dataset file

---

## Compiler Extensions

$\color{#a65450}\mathrm{DogLeash}$ Research Objects are assumed to be $\color{#a65450}\text{C}\large{}\text{++}$ code libraries that compile to a single recognized 
Research Application (other utilities may be created as well, but someone using the data set should 
launch a single executable to access most or all available information and functionality).  In general, 
an Executable Research Object will include dataset-specific code for data deserialization, 
processing, analysis, visualization, and search capabilities.  Important procedures within this code 
should, as a rule, be exposed or wrapped in a remote-callable manner.

Assuming a Research Application is primarily implemented in $\color{#a65450}\text{C}\large{}\text{++}$, users should have the option of 
extending or fine-tuning this code without writing their own $\color{#a65450}\text{C}\large{}\text{++}$ files that would need a separate 
compile/build step.  In short, Research Applications should have scripting capabilities.  Many 
scripting languages are possible, of course, but ideally the scripting framework should 
be compiled directly inside Research Object, rather than relying on an external 
interpreter.  Languages such as $\color{#a65450}\mathrm{Lua}$, $\color{#a65450}\mathrm{AngelScript}$, and $\color{#a65450}\mathrm{ECL}$ (Embeddable Common Lisp) are examples 
of scripting platforms that may be distributed in source-code fashion alongside host applications.

If a more minimal scripting environment is sufficient, $\color{#a65450}\mathrm{DogLeash}$ allows programmers to build a 
scripting framework that is tightly integrated with other components in an 
Executable Research Object.  Here is a summary of some features and techniques.

**_C++ Interop_**

The first issue is exposing $\color{#a65450}\text{C}\large{}\text{++}$ procedures/methods to the script runtime.  The point here is that 
arguments are (at first) encoded in generic containers such as $\color{#a65450}\mathrm{QVariant}$ or $\color{#a65450}\mathrm{QStringList}$ 
(assuming we are working in a $\color{#a65450}\mathrm{Qt}$ environment).  We need to convert these to local 
variables that get passed on the stack (or alter the stack some other way &mdash; $\color{#a65450}\mathrm{AngelScript}$ actually 
employs inline assembly code).  This seems like an impasse because we do not know the arguments&rsquo;
types ahead of time.  There is a workaround, however &mdash; even without heavy introspection and 
dependencies such as $\color{#a65450}\mathrm{LLVM}$ &mdash; which can be illustrated with code adopted from 
$\color{#a65450}\mathrm{rpclib}$ ([github.com/rpclib/rpclib](https://github.com/rpclib/rpclib)):


```
typedef std::function<void (QStringList)> ftype; // copy-on-write, 
 // so we don't need to pass by & const

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
wrapper all of which have the same type (here using $\color{#a65450}\mathrm{QStringList}\text{)}$.  There's a little more work 
to do, particularly to handle return values (plus maybe exceptions and pointer-to-members), but this is the basic idea.

We need a different technique for dynamically loaded libraries, however, because in that case we 
*don't* have signatures at compile time, so no `_func_traits` or `tuple_element`.  However, we 
can handle many or most functions that might be exposed for a data set.  Typically these 
fit familiar patterns that can be summarized with a compact code.  For instance, use numbers 
like 1, 2, 4, 8 for integers of different sizes.  Then a pair of 4-byte arguments with no return 
could get a code like 440, and a wrapper constructured for every procedure with that kind of 
signature (or anything binary compatible to it), rather than one-wrapper-per-function as above:

```
void call_440(fn_type fn, QStringList args)
{
 quint32 arg1 = args[0].toUInt();
 quint32 arg2 = args[1].toUInt();
 fn(arg1, arg2);
}
```

A slew of wrappers in the form `call_XXX` could be produced via code generators, and dispatchers 
selected via a string of `switch` statements: one for the arg count, next for the arg1 type 
(e.g., 1, 2, 4, or 8), next the arg2 type, etc.  Those `switch`es would work off of digits in 
the signture &ldquo;code&rdquo; (like 440) so that registering even an $\color{#a65450}\mathrm{.so}$ runtime procedure 
would take only a single numeric code (which is simpler than how registering works 
in $\color{#a65450}\mathrm{ECL}$ or $\color{#a65450}\mathrm{AngelScript}\text{)}$.


**_Signature Codes_**

The problem with this technique is that only a relatively limited set of signatures can be 
supported &mdash; a compilation unit can have only so many `switch` cases.  $\color{#a65450}\mathrm{DogLeash}$ tries 
to extend the range of available procedures by employing a more indirect signature-code 
mechanism.  Note that the count of signature patterns is affected by the number 
of distinct types a function takes as parameters.  For instance, if all arguments have 
the same type, then the only thing that varies is the number of parameters, so there's a 
maximum of say 10 `switch` cases $\text{(}\color{#a65450}\mathrm{Qt}$'s meta-object system, for $\color{#a65450}\mathrm{QObject}$ subclasses, 
recognizes up to 10 arguments).  If there are two types, then a variety of argpack-sizes 
can be covered by bit vectors (on for one type and off for the other).  It's only with three 
or more types that you get potentially complex dispatch trees, but you're also problably 
not going to get a lot of *repetition*.  Suppose you have exactly three arguments of 
three different types: each signature is then a permutation of three elements, of which 
there are only six, plus `switch` cases for the types involved.

By &ldquo;types&rdquo; here I mean any collection of binary-compatible types: we can cast a function-pointer 
to a generic signature based on unsigned integers, for example.  The actual procedures 
might take signed integers instead, or `enum` values, but can be correctly called via 
that partially-type-erased pointer instead.  In any case, $\color{#a65450}\mathrm{RedPatch}$ has 
sample code representing dispatch-tables sufficient for most signatures one might 
need to expose from a library.

**_Language Server Protocol_**

The $\color{#a65450}\mathrm{Language Server Protocol}$ $\text{(}\color{#a65450}\mathrm{LSP}\text{)}$, developed by Microsoft, is a tool through which 
code editors and Integrated Development Environments $\text{(}\color{#a65450}\mathrm{IDE}\text{s}$) communicate 
with external programs that play the role of code assistants, 
offering hints, information on data types and function signatures, code completion 
suggestion, etc.  For example, $\color{#a65450}\mathrm{Clangd}$ is the preeminent Language Server 
for $\color{#a65450}\text{C}\large{}\text{++}$.

The $\color{#a65450}\mathrm{LSP}$ model is flexible, and a variety of different software components 
can be useful Language Servers.  It is not necessary to fully parse 
source files, as $\color{#a65450}\mathrm{Clangd}$ does; depending on the language and the server 
it may be possible to build more limited views onto source code 
which still can be helpful for certain $\color{#a65450}\mathrm{LSP}$ requests.  Language 
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
dispatch.  Continuing the above $\color{#a65450}\mathrm{RPC}$ example, functions&rsquo; 
names and signature codes are the kind of information that could be 
exposed via metadata files.

By way of illustration, the following is an example of how 
to use $\color{#a65450}\mathrm{LLVM}$ $\color{#a65450}\mathrm{IRBuilder}$ code, generated by Google $\color{#a65450}\mathrm{AI}$:

```
Type *Int32Ty = Type::getInt32Ty(Context);
std::vector<Type*> ParamTypes = {Int32Ty, Int32Ty};
FunctionType *FuncType = FunctionType::get(Int32Ty, ParamTypes, false);
Function *AddFunc = Function::Create(FuncType, Function::ExternalLinkage, &ldquo;add", OwnerModule.get());

Function::arg_iterator Args = AddFunc->arg_begin();
Value *ArgA = Args++;
ArgA->setName("a");
Value *ArgB = Args;
ArgB->setName("b");
```

But this is quite similar to how we would populate a function-call at runtime, to be passed 
to one of the dispatch protocols outlined above.  Let's imagine wrapping the $\color{#a65450}\mathrm{IRBuilder}$ 
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

With very few changes (maybe the last line becomes some sort of $\color{#a65450}\mathrm{call}$ instruction instead) this might be 
almost identical to VM instructions for an $\color{#a65450}\mathrm{FFI}$-style call intead.

The point is that a standardized type-metadata format could be used simultaneously both to 
feed information to Language Servers and to enable Script Hosting (and, by 
extension, query evaluation).  That's the rationale behind $\color{#a65450}\mathrm{DogLeash}$ as a Language Server 
*and* Script Host (the &ldquo;leash&rdquo;) and the basis for the $\color{#a65450}\mathrm{Qynviper}$ 
modules mentioned above.

---

<a id="sample-documents-raised"></a>

## Sample Documents

The following are examples of my own publications (not in chronological order) 
developed with $\color{#a65450}\mathrm{DogLeash}$ code in some iteration.

(&#x22b9; Orcid: [0000-0002-0988-7352](https://orcid.org/0000-0002-0988-7352))

- [Merging Full-Text Query with Research Data Sets: A perspective from compiler theory](https://scignscape.github.io/Rinc-XOA/documents/A-perspective-from-compiler-theory.pdf)  Presented at NISO/JATS 2026.

 &nbsp; &nbsp; &#x2192; Slide deck: 
[Nathaniel_Christen_JATS-Con-2026-slides](https://scignscape.github.io/Rinc-XOA/documents/Nathaniel_Christen_JATS-Con-2026-slides.pdf)

- [Ordering Conceptual Synthesis: The Implications of Cognitive Phenomenology for Syntactic Theory](https://scignscape.github.io/Rinc-XOA/authors/NathanielChristen/OrderingConceptualSynthesis.pdf)
A paper about linguistics and the philosophy of science, which uses 
programming languages as case-studies for some 
linguistic topics.  The Executable Research Object code 
for this manuscript included document-specific 
algorithms to isolate linguistic samples and present 
them alongside the index as a kind of thematic summary.

- &ldquo;From &lsquo;Naturalizing Phenomenology&rsquo; to Formalizing 
Cognitive Linguistics (I-III)&rdquo;  These three papers were 
developed in connection with supplemental materials 
for an article in the International Journal of 
Speech Technology, where I joined as a co-author 
with researchers from Bar-Ilan University (Israel) 
and Johns Hopkins ($\color{#a65450}\mathrm{US}$).  The supplemental content 
was a data set including audio and written 
samples for linguistic annotation, including some 
taken as &ldquo;hypothetical&rdquo; sentences or fragments 
created to illustrate linguistic themes or 
theories.  I wrote three supplemental essays to analyze 
material present in the data set.  Within those 
papers, I notated new or previously-discussed 
linguistic samples, and employed $\color{#a65450}\mathrm{DogLeash}$ to 
pull those examples as structured data available 
to readers as part of the dataset package; in short, 
the code demonstrated techniques for compiling 
linguistic data sets from example 
sentences/fragments listed for analysis in linguistics papers.

    1.  [From &lsquo;Naturalizing Phenomenology&rsquo; to Formalizing Cognitive Linguistics (I):
Cognitive Transform Grammar](https://scignscape.github.io/Rinc-XOA/documents/ijst/ctg.pdf)

    2.  [From &lsquo;Naturalizing Phenomenology&rsquo; to Formalizing Cognitive Linguistics (II):
Grounding and Center/Peripheral Relations](https://scignscape.github.io/Rinc-XOA/documents/ijst/icg.pdf)

    3.  [From &lsquo;Naturalizing Phenomenology&rsquo; to Formalizing Cognitive Linguistics (III):
Externalism and the Interface Theory of Meaning](https://scignscape.github.io/Rinc-XOA/documents/ijst/itm.pdf)

 &nbsp; &nbsp; &#x2606; Data Set and $\color{#a65450}\mathrm{PDF}\color{black}\textsf{s}$
on Open Science Framework: [osf.io/gd37f](https://osf.io/gd37f/overview)



- The chapters of the book _Innovative Data Integration and Conceptual Space Modeling 
for COVID, Cancer, and Cardiac Care_ (Elsevier, 2022).  These are individual 
chapters&rsquo; penultimate versions, 
not identical to the printed book.

  1.  [Chapter 1 &ndash; Introduction](https://scignscape.github.io/Rinc-XOA/documents/data-integration/Chapter1.pdf)
  2.  [Chapter 2 &ndash; Data Structures Associated with Biomedical Research](https://scignscape.github.io/Rinc-XOA/documents/data-integration/Chapter2.pdf)
  3.  [Chapter 3 &ndash; Data Mining and Predictive Analytics for Cancer and COVID-19](https://scignscape.github.io/Rinc-XOA/documents/data-integration/Chapter3.pdf)
  4.  [Chapter 4 &ndash; Modular Design, Image Biomarkers, and Radiomics](https://scignscape.github.io/Rinc-XOA/documents/data-integration/Chapter4.pdf)
  5.  [Chapter 5 &ndash; Types’ Internal Structure and ‘Nonconstructive’ (‘NC4’) Type Theory](https://scignscape.github.io/Rinc-XOA/documents/data-integration/Chapter5.pdf)
  6.  [Chapter 6 &ndash; Using Code Models to Instantiate Data Models](https://scignscape.github.io/Rinc-XOA/documents/data-integration/Chapter6.pdf)
  7.  [Chapter 7 &ndash; Multi-Aspect Modules and Image Annotation](https://scignscape.github.io/Rinc-XOA/documents/data-integration/Chapter7.pdf)
  8.  [Chapter 8 &ndash; Image Annotation as a Multi-Aspect Case-Study](https://scignscape.github.io/Rinc-XOA/documents/data-integration/Chapter8.pdf)
  9.  [Chapter 9 &ndash; Conceptual Spaces and Scientific Data Models](https://scignscape.github.io/Rinc-XOA/documents/data-integration/Chapter9.pdf)

- Five chapters from the book _AI, IoT, Big Data and Cloud Computing for Industry 4.0_ 
(Amy Neustein, Parikshit N. Mahalle, Prachi Joshi, Gitanjali Rahul Shinde, eds., 
Springer 2024: [https://link.springer.com/book/10.1007/978-3-031-29713-7](https://link.springer.com/book/10.1007/978-3-031-29713-7)).

    1.  [Chapter 20 &ndash; Multi-Component Interoperability and Virtual Machines: Examples from
Architecture, Engineering, Cyber-Physical Networks, and Geographic Information Systems](https://scignscape.github.io/Rinc-XOA/documents/iot/ch20.pdf)

    2.  [Chapter 21 &ndash; Virtual Machines and Hypergraph Data/Code Models: Graph-Theoretic
Representations of Lambda-Style Calculi](https://scignscape.github.io/Rinc-XOA/documents/iot/ch21.pdf)

    3.  [Chapter 22 &ndash; GUI Integration and Virtual Machine Constructions for Image Processing:
Phenomenological and Database-Engineering insights into Computer Vision](https://scignscape.github.io/Rinc-XOA/documents/iot/ch22.pdf)

    4.  [Chapter 23 &ndash; The Missing Links Between Computer and Human Languages: Animal Cognition
and Robotics](https://scignscape.github.io/Rinc-XOA/documents/iot/ch23.pdf)

    5.  [Chapter 24 &ndash; GUIs, Robots, and Language: Toward a Neo-Davidsonian Procedural Semantics](https://scignscape.github.io/Rinc-XOA/documents/iot/ch24.pdf)


- My doctoral dissertation on &ldquo;[Phenomenological Reductionism](https://scignscape.github.io/Rinc-XOA/documents/nc/dissertation.pdf)&rdquo;.  This document has fairly basic layout, but I still stand by the content.


---


# Other Projects and Documents Using DogLeash

Due to privacy or copyright issues, for some of these examples 
I can only describe projects and their unique coding 
requirements.  In other cases this list will include 
links to $\color{#a65450}\mathrm{PDF}$ documents illustrating some $\color{#a65450}\mathrm{DogLeash}$ features.

###  Projects Involving Data and/or Code Packages

1.  $\color{#a65450}\mathrm{CSV}$ and $\color{#a65450}\mathrm{SVG}$ 
Integration:  This project coincided with the five-year cycle 
for the Environmental Protection Agency's &ldquo;Hazard Mitigation&rdquo; plan.  As part 
of this $\color{#a65450}\mathrm{EPA}$ program, states and counties are required to submit documentation 
for how they identify and address environmental dangers in their 
communities.  Here, I used $\color{#a65450}\mathrm{DogLeash}$ tools to address both environmental 
data and Zoning/Land Use ordinances so as to explore the connections 
between environmental health and urban development.  Part of this 
project involved extending a New York City tool called 
$\color{#a65450}\mathrm{ZoLa}$ (for Zoning and Land Use), which was created by 
NYC Planning Labs but openly shared in the hopes that 
other jurisdictions adopt the same technology.  Other 
data sourecs came from the 
$\color{#a65450}\mathrm{EPA}$ &ldquo;Toxic Release Inventory&rdquo; $\text{(}\color{#a65450}\mathrm{TRI}\text{)}$ 
data set, which publishes data files identifying reported 
contamination incidents by geographic coordinates, and 
has been studied for publications such as the New York City &ldquo;Environmental Justice&rdquo; 
$\color{black}\textbf{(}\color{#a65450}\mathrm{EJNYC}\color{black}\textbf{)}$
report and mapping tool.  My goal was to examine how 
data sets such as $\color{#a65450}\mathrm{TRI}$, along with environmental-impact 
data presented by states or private organizations, could be cross-referenced 
with Zoning and Land Use maps.  Demonstration code included $\color{#a65450}\mathrm{CSV}$ deserializers 
to handle to complex $\color{#a65450}\mathrm{TRI}$ data structures, that were hierarchical 
more than tabular in nature but used $\color{#a65450}\mathrm{CSV}$ as a rough serialization tool, 
as well as native-compiled $\color{#a65450}\mathrm{GUI}$ components based on $\color{#a65450}\mathrm{OpenStreetMap}$ 
for $\color{#a65450}\mathrm{GIS}$ displays.

    During this work I identified a series of errors with the $\color{#a65450}\mathrm{TRI}$ encoding and 
documentation, so another layor of components implemented for this project 
involved mapping $\color{#a65450}\mathrm{TRI}$-related $\color{#a65450}\mathrm{PDF}$ files to $\color{#a65450}\mathrm{SVG}$, so that I could 
superimpose annotations identifying the $\color{#a65450}\mathrm{TRI}$ problems and 
how they could be corrected in code. 


2.  Annotated Legal Documents:  This was another project leveraging 
$\color{#a65450}\mathrm{PDF}$ to $\color{#a65450}\mathrm{SVG}$ conversion.  The basic material for this project 
was a collection of legal documents that had been merged into a 
single file and then annotated to show patterns of 
behavior.  Applying techniques from ethnomethodology, the annotator 
designed a controlled vocabuly to insert terms functioning 
as &ldquo;handles&rdquo; into $\color{#a65450}\mathrm{PDF}$ comment boxes.  I then implemented 
code which scanned these $\color{#a65450}\mathrm{PDF}$ annotations and identified 
sub-documents which, according to the annotator, 
exhibited various patterns of communicative behavior.  I then 
split the larger $\color{#a65450}\mathrm{PDF}$ into multiple subdocuments and mapped 
that content to hybrid $\color{#a65450}\mathrm{HTML}\color{black}/\color{#a65450}\mathrm{SVG}$ pages, together with an 
online index that showed annotated classifications for 
each subdocument, plus page-by-page as well as document-by-document 
navigation for the linked pages.  The overall package was presented 
to a judge as a user-friendly alternative to submitting the 
original manuscript as a monolithic item of evidence. 

3.  Building a Book's Second Edition:  This project involved merging 
additional material added by the authors into a book they had 
initially published in 2005.  We built an in-house full $\color{#a65450}\mathrm{PDF}$ 
of the new edition that mimicked the style and layout of the 
preparatory manuscripts shared by the publishers.  By cross-referencing 
the two versions, we were able to identify errors made on the 
publisher's end by copy editors and also fine-tune the new material.
Significant effort went into creating and updated index.  Special 
$\color{#a65450}\mathrm{DogLeash}$ tools laid a foundation for custom $\color{#a65450}\mathrm{GUI}\text{s}$ whose goal 
was to compare the first- and second-edition manuscripts to 
ensure that all previous index entries were migrated to the 
updated book, as well as creating new index material in the 
pbulisher's desired metadata format.

4.  Examining Biomedical Software:  During the Covid pandemic, 
I wrote the text for a book called _Innovative Data Integration and Conceptual 
Space Modeling for COVID, Cancer, and Cardiac Care_ (Elsevier, 
2022).  This book included a detailed examination of certain 
software components &mdash; such as the Cancer Phenomics Toolkit $\text{(}\color{#a65450}\mathrm{CapTk}\text{)}$, 
$\color{#a65450}\mathrm{IQmol}$ molecular visualization software, $\color{#a65450}\mathrm{cytolib}$ for flow cytometry, 
$\color{#a65450}\mathrm{medInria}$ and $\color{#a65450}\mathrm{Semantic PACS}$ (Picture Archiving and Communication System), 
and the Cancer Bioinformatics Grid $\text{(}\color{#a65450}\mathrm{caBig}\text{)}$ Image Annotation Toolkit &mdash; 
bioinformatics file formats (and their deserialization/analytic libaries), 
and collaborative projects (such as $\color{#a65450}\mathrm{caBig}$'s &ldquo;Digital Model Repository&rdquo; 
and the $\color{#a65450}\mathrm{CORD\text{-}19}$ archive for Covid research).  $\color{#a65450}\mathrm{CORD\text{-}19}$ (the 
$\color{#a65450}\mathrm{COVID\text{-}19}$ Open Research Dataset) grew to encompass over 400,000 open-access 
articles focusing on $\color{#a65450}\mathrm{SARS\text{-}COV\text{-}2}$ and related topics (including the original 
$\color{#a65450}\mathrm{SARS}$ epidemic and Coronavirus biology in general) with freely-available 
full-text encoding.  The goal of $\color{#a65450}\mathrm{CORD\text{-}19}$ was to help scientists in 
different areas addressing the pandemic (viral morphology, infectious 
mechanisms, diagnostics, clinical treatment assesment, vaccine development, 
genomics, variants/mutations, epidemiology, long-term effects) discover 
resources or research that could augment their own work, helping 
piece together the Covid puzzle.  Unfortunately, much of $\color{#a65450}\mathrm{CORD\text{-}19}$'s
implementation depended on $\color{#a65450}\mathrm{PDF}$ text extraction, which 
yielded errors and limitations I analyzed in the Elsevier book.
The $\color{#a65450}\mathrm{CORD\text{-}19}$ curators (from Allen Institute for 
$\color{#a65450}\mathrm{AI}$) were open about these problems and 
even issued a &ldquo;call to action&rdquo; requesting publishers to 
develop and adopt more rigorous text-encoding 
methods:

    >   Though the full text of many scientific papers are available to researchers through CORD\text{-}19, a number of challenges prevent easy application of NLP and text mining techniques to these papers.
First, the primary distribution format of scientific papers &mdash; PDF &mdash; 
is not amenable to text processing. The PDF file format is designed to share electronic documents rendered faithfully for reading and printing, and mixes visual with semantic information. Significant effort is needed to 
coerce PDF into a format more amenable to text mining, such as JATS XML, BioC, ... or 
S2ORC JSON ... [W]e can still benefit from better PDF parsing 
tools for scientific documents.  As a complement, scientific papers should also be made available in a structured format like JSON, XML, or HTML.

    Hopefully $\color{#a65450}\mathrm{DogLeash}$ can contribute to this initiative. 

    Apart from text representations responding to the Allen Institute 
&ldquo;call to action&rdquo;, the special code for this book involved 
compiling and, in some cases, extending bioinformatics 
or scientific software applicable to biomedical 
research.  One of the book's themes was how to implement data-integration 
protocols that could unify disparate applications into 
executable research collaborations.  Much of the book's discussion 
was shaped by prototypes for plugins or extensions 
to software commonly used for research or lab services 
in fields such as organic chemistry, tumor simulations, 
systems biology, bioimaging, and Computer Vision.












