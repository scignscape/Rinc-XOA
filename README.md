
# Rinc-XOA : Research in nonprofit contexts - Executable Open Access

If you are interested particularly in the $\color{#365450}{\mathrm{\large{}RedPatch}}$ Community Health research platform, 
that's detailed in this repository's $\color{#365450}{\mathrm{\large{}RedPatch}}$ branch or [skip ahead](#red-patch).

For a description of several projects that employed some of the code published here, 
including a list of open-access articles and book chapters, scroll down or [skip ahead](#sample-documents-raised).

Many of these components are built around a new Virtual Machine generator called 
$\underline{\color{#3e2a47}{\mathrm{\small Qynviper}}}$; for details on that, scroll down or [skip ahead](#qynviper).


---

### Overview

In publishing, Diamond $\text{(}\color{#365450}{\mathrm{\large{}DiamondOA}}\text{)}$ is the most complete Open Access model, with no fees either for authors (i.e., Article Processing Charges 
$\color{black}{\small{}(}\color{#365450}{\mathrm{\large{}APC}}$ s)) or readers (i.e., article paywalls).  The work needed to prepare manuscripts for publication is either performed on a volunteer basis or supported by "Diamond Open Access Funds", which are more prevalent in the European Union than the United State.

Meanwhile, Executable Research Objects $\text{(}\color{#365450}{\mathrm{\large{}ERO}}\text{s}$) are one form of Research Object/data set guided by data transparency and $\color{#365450}{\mathrm{\large{}FAIRsharing}}$ (Findable, Accessible, Interoperable, Reusable) principles.  Research Objects in general may include multiple forms of digital assets (text, code, raw data files, and perhaps multimedia content) which can present challenges for in-depth usage.  An *Executable* Research Object in particular provides a single Research Application that serves as an entry point or overarching resource streamlining access to the variegated parts of a data publication.  In general, these Research Applications are standalone desktop-style programs which, when launched, will provide visual summaries and windows to manage data set records, as well as viewers for other media types $\text{(}\color{#365450}{\mathrm{\large{}PDF}}$ documents, images, videos, digital maps, etc.).

For the current repository and siblings, Executable Open Access $\text{(}\color{#365450}{\mathrm{\large{}XOA}}\text{)}$ designates a synthesis of these two paradigms.  Most FAIRsharing projects, to be sure, are Open Access by default because they are hosted on free services such as Open Science Framework $\text{(}\color{#365450}{\mathrm{\large{}OSF}}\text{)}$ or Dryad -- often linked to publications via "Data Availability" or "Supplemental Materials" sections on articles' landing pages (which also have abstracts, bibliographies, and so forth).  There is no such thing as a "dataset processing charge".  Nonetheless, $\color{#365450}{\mathrm{\large{}ERO}}\text{s}$ are most productive when they include complete version of associated research articles -- both in human-readable (e.g., $\color{#365450}{\mathrm{\large{}PDF}}\text{)}$ and machine-readable (e.g., $\color{#365450}{\mathrm{\large{}JATS}}$ $\color{#365450}{\mathrm{\large{}XML}}\text{)}$ formats, which requires that the entire package be governed by a $\color{#365450}{\mathrm{\large{}DiamondOA}}$ licence.  Moreover, aggregating disparate dataset materials into an overarching Research Application requires additional programming that could potentially be supported by $\color{#365450}{\mathrm{\large{}DiamondOA}}$ funds or similar initiatives.  In short, the $\color{#365450}{\mathrm{\large{}ERO}}$ and $\color{#365450}{\mathrm{\large{}DiamondOA}}$ paradigms are sufficiently interrelated/overlapping that each may help promote the other.

}}$Rinc-XOA}}$ (this repository) has a sibling repo called $\color{#365450}{\mathrm{\large{}DogLeash}}$ (Diamond Object Grid - Language Server and Script Host), at [github.com/ScignScape/DogLeash](https://github.com/scignscape/DogLeash/) which holds most of the actual code.  This code base is intended to provide tools and templates for Executable Research Objects.  $\color{#365450}{\mathrm{\large{}DogLeash}}$ provides several "modules" for specific subject areas and implementation requirements, such as Medical Imaging, Geographic Information Systems, and Compiler Extensions.  A $\color{#365450}{\mathrm{\large{}Rinc-XOA}}$ project can include any modules relevant to its topic.

---

<a id="red-patch"></a>

### Qynviper Modules

A Qynviper VM -- "query/native interop compiler" -- can be implemented via code published in $\color{#365450}{\mathrm{\large{}RedPatch}}$.  The idea 
behind Qynviper is that opcodes delegate to methods in $\color{#365450}{\mathrm{\large{}C++}}$ classes (or potentially those of other languages).  Each such class is called a "module".  By selecting a group of modules, individual VMs can target capabilities to their use-cases.  For example, a VM may be engineered as a compilation target for imperative/procedure scripting languages -- with support for lexical scopes, variables, function calls, and so forth -- but in other use-cases -- e.g., object deserialization -- VM blocks are generated from $\color{#365450}{\mathrm{\large{}XML}}$ or $\color{#365450}{\mathrm{\large{}JSON}}$ sources which are declarative rather than imperative.  A conventional $\color{#365450}{\mathrm{\large{}C++}}$ $\color{#365450}{\mathrm{\large{}SAX}}$ parser responds immediately to $\color{#365450}{\mathrm{\large{}XML}}$ parsing events, thereby conflating $\color{#365450}{\mathrm{\large{}DTD}}$ and handler logic, whereas a VM can partition the problem into two almost entirely separate domains (generating VM instruction sequences versus implementing opcode handlers).  The Qynviper components make heavy use of preprocessor macros, and in general it takes just a few minutes to rig up $\color{#365450}{\mathrm{\large{}C++}}$ classes as modules once the actual opcode methods are implemented.

The $\color{#365450}{\mathrm{\large{}RedPatch}}$ sources (outlined next) are built 
around several VMs created in this manner, partly for demonstration purposes.  This includes document processors for publications -- see the sample "Ordering Concepual Synthesis" paper linked below, or 
[here](https://scignscape.github.io/Rinc-XOA/authors/NathanielChristen/OrderingConceptualSynthesis.pdf).  The paper provides links to five other representations targeting different text-encoding specifications, such as $\color{#365450}{\mathrm{\large{}RO-Crate}}$ and $\color{#365450}{\mathrm{\large{}TAGML}}$ (Text-As-Graph Markup Language).  Here, these are not markup formats directly (though when needed convertable to/from $\color{#365450}{\mathrm{\large{}XML}}$ or $\color{#365450}{\mathrm{\large{}JSON}}\text{)}$ but rather Qynviper code used at different points in a publishing workflow.

**_AMPATH Forms_**

In addition to document preparation, $\color{#365450}{\mathrm{\large{}RedPatch}}$ illustrates other VM examples for use-cases such as object deserialization.  For instance, one Qynviper module is built around $\color{#365450}{\mathrm{\large{}AMPATH}}$ -- the "Academic Model Providing Access To Healthcare" -- which sponsors Electronic Health Record software used by NGOs such as Doctors Without Borders.  Although eventually rendered as $\color{#365450}{\mathrm{\large{}HTML}}$ (via $\color{#365450}{\mathrm{\large{}ReactJS}}\text{)}$ these records are intrinsically defined as $\color{#365450}{\mathrm{\large{}JSON}}$ configuration files, which opens the possibility for generating alternative front-end viewers.  The $\color{#365450}{\mathrm{\large{}RedPatch}}$ branch shows an example where $\color{#365450}{\mathrm{\large{}AMPATH}}$ forms are translated to $\color{#365450}{\mathrm{\large{}C++}}$ $\color{#365450}{\mathrm{\large{}Qt}}$ classes and compiled as ordinary desktop libraries (or standalone applications).  Such a "native rendering engine" is potentially useful in providing an $\color{#365450}{\mathrm{\large{}EHR}}$ framework which does not depend on $\color{#365450}{\mathrm{\large{}HTTP}}$ servers and client/server networking, and it also shows how $\color{#365450}{\mathrm{\large{}AMPATH}}$ annotations (with sources such as Open Concept Lab and other biomedical controlled vocabularies) can augment the searchability and interoperability of $\color{#365450}{\mathrm{\large{}C++}}$ $\color{#365450}{\mathrm{\large{}GUI}}$ components.  The role of Qynviper here is one of generating $\color{#365450}{\mathrm{\large{}C++}}$ code: $\color{#365450}{\mathrm{\large{}AMPATH}}$ configuration files are first parsed into VM scripts which are separately executed to create the final $\color{#365450}{\mathrm{\large{}GUI}}$ code.

**_DCMTK_**

Another similar example, based on $\color{#365450}{\mathrm{\large{}XML}}$ rather than $\color{#365450}{\mathrm{\large{}JSON}}$, provides an extension to the widely-used $\color{#365450}{\mathrm{\large{}DCMTK}}$ library for working with $\color{#365450}{\mathrm{\large{}DICOM}}$ (Digital Imaging and Communications in Medicine) series.  This library offers multiple utilities for converting $\color{#365450}{\mathrm{\large{}DICOM}}$ files to other image and data formats $\text{(}\color{#365450}{\mathrm{\large{}XML}}$, $\color{#365450}{\mathrm{\large{}HTML}}$, $\color{#365450}{\mathrm{\large{}JPEG}}$ and so forth) but currently lacks support for other diagnostic-imaging formats, such as $\color{#365450}{\mathrm{\large{}MI-CDM}}$ (Medical Imaging Common Data Model), 
part of the $\color{#365450}{\mathrm{\large{}OMOP-CDM}}$ (Observational Medical Outcomes Partnership) Common Data Model.  For publishing medical-imaging research (topics such as AI Segmentation and Neuroimaging) it would also be helpful to map $\color{#365450}{\mathrm{\large{}DSR}}$ (Structured Reporting) observations, annotations, and "key" images onto common Open Science formats such as $\color{#365450}{\mathrm{\large{}RO-Crate}}$.  For these use-cases, $\color{#365450}{\mathrm{\large{}RedPatch}}$ provides a Qynviper VM whose purpose is to parse $\color{#365450}{\mathrm{\large{}dcm2xml}}$ and $\color{#365450}{\mathrm{\large{}dsr2xml}}$ output and dispatch calls to code-generators for formats not currently supported by $\color{#365450}{\mathrm{\large{}DCMTK}}$.

As a mostly self-contained platform, Qynviper VMs can readily be embedded in host applications, such as $\color{#365450}{\mathrm{\large{}3DSlicer}}$ (the preeminent research tool for medical imaging and $\color{#365450}{\mathrm{\large{}DICOM}}$ series).

---

<a id="red-patch"></a>

### Community Health Research Platform


I have grouped most of the $\color{#365450}{\mathrm{\large DogLeash}}$ modules into <span style='color:red!10!blue;background:#ede8ff'>RedPatch}}$ (Research Objects - Diamond Open Access Targeting Children's and Community Health) which has its own branch in the current repository.  This code base leverages similarities between Electronic Health Records and Executable Research Object "microcomponents".  More specifically, at least for $\color{#365450}{\mathrm{\large{}DogLeash}}$ an Executable Research Object is composed of multiple microcomponents which, in general, each provide one application window and present the user with information and/or graphics from a particular data profile, multimedia resource, or record source (data base, data set, $\color{#365450}{\mathrm{\large{}CSV}}$/}}$XML}}$/}}$JSON}}$ file, etc.).  A good example of microcomponents would be displays showing a specific type of $\color{#365450}{\mathrm{\large{}EHR}}$ form, or a single medical image alongside provenance, diagnostic, and annotation metadata.  In $\color{#365450}{\mathrm{\large{}DogLeash}}$, for each microcomponent there is typically a single $\color{#365450}{\mathrm{\large{}C++}}$ class encapsulating the totality of information provided by one instance of the component, plus metadata about valid ranges/values for form fields and annotations on fields/enumerations in terms of standard vocabularies, such as Open Concept Lab.

Electronic Health Records and Medical Imaging is therefore a useful domain in which to implement concrete $\color{#365450}{\mathrm{\large{}DogLeash}}$ components.  This does not mean that Executable Research Objects should mimic on-site $\color{#365450}{\mathrm{\large{}EHR}}$ forms used by health-care providers for their day-to-day operations; but special-purpose "research" forms may be developed that have similar presentation and terminological standards, and such forms in turn for the basis of open-access data sets.

For more details, navigate to the $\color{#365450}{\mathrm{\large{}RedPatch}}$ branch or click [here](https://github.com/scignscape/Rinc-XOA/tree/RedPatch).

---

### Publishing for Nonprofits

Supporting research in nonprofit contexts presents several distinct paradigms as compared with publishing workflows in traditional academic environments.  For one thing, authors are not necessarily affiliated with universities; they might instead be nonprofits' employees, volunteers, or independent researchers.  Outlets might not be conventional peer-reviewed journals or book series.  Some nonprofits act as their own miniature publishing houses; in other cases researchers may use platforms such as $\color{#365450}{\mathrm{\large{}github}}$, Open Science Framework, or Dryad.  A single document publication (e.g., the $\color{#365450}{\mathrm{\large{}PDF}}$ of a research article) in this case may be just one file in a Research Object also containing source code and raw data files.

Insofar as publications are deployed with the same licences as code and data, they can be rigorously cross-referenced with sibling assets to an extent that is not feasible when documents are paywalled while data sets are not.  This use case is not well-supported by existing document-prep languages like $\color{#365450}{\mathrm{\large{}LaTeX}}$ or $\color{#365450}{\mathrm{\large{}JATS}}$, so $\color{#365450}{\mathrm{\large{}DogLeash}}$ provides its own input markup language, machine-readable text encoding, $\color{#365450}{\mathrm{\large{}PDF}}$ annotation system, and custom $\color{#365450}{\mathrm{\large{}PDF}}$ viewers (all of which may embedded direcly in Executable Research Objects as $\color{#365450}{\mathrm{\large{}C++}}$ source files).  In this context, for example, articles are displayed via $\color{#365450}{\mathrm{\large{}PDF}}$ files that may be viewed within $\color{#365450}{\mathrm{\large{}PDF}}$ renderers built as part of the Research Object (i.e., Research Application) itself.

**_The "Diamond" Publishing Model_**

In contemporary academic publishing, the basic unit for sharing experience and ideas often is not a single manuscript, but rather a collection of files packaging variegated content-types, including $\color{#365450}{\mathrm{\large{}PDF}}$ files for viewing documents, but also machine-readable text encoding, computer code, raw data, and statistical/graphics summaries.  These packages typically adhere to collaborative standards such as Research Object Bundles, Executable Research Objects, $\color{#365450}{\mathrm{\large{}FAIR}}$-sharing, and research-grid specifications for packages deposited on decentralized but searchable community networks.

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
such as customized $\color{#365450}{\mathrm{\large{}PDF}}$ viewers specifically designed for a shared data package.

In brief, the diamond model is not only more ethical; it also permits technological 
enhancements that are impossible otherwise.  In particular, it becomes possible 
to implement a rigorous interop and query infrastructure that emcompasses both text manuscripts 
and dataset file

---

### Compiler Extensions

}}$DogLeash}}$ Research Objects are assumed to be $\color{#365450}{\mathrm{\large{}C++}}$ code libraries that compile to a single recognized 
Research Application (other utilities may be created as well, but someone using the data set should 
launch a single executable to access most or all available information and functionality).  In general, 
an Executable Research Object will include dataset-specific code for data deserialization, 
processing, analysis, visualization, and search capabilities.  Important procedures within this code 
should, as a rule, be exposed or wrapped in a remote-callable manner.

Assuming a Research Application is primarily implemented in $\color{#365450}{\mathrm{\large{}C++}}$, users should have the option of 
extending or fine-tuning this code without writing their own $\color{#365450}{\mathrm{\large{}C++}}$ files that would need a separate 
compile/build step.  In short, Research Applications should have scripting capabilities.  Many 
scripting languages are possible, of course, but ideally the scripting framework should 
be compiled directly inside Research Object, rather than relying on an external 
interpreter.  Languages such as $\color{#365450}{\mathrm{\large{}Lua}}$, $\color{#365450}{\mathrm{\large{}AngelScript}}$, and $\color{#365450}{\mathrm{\large{}ECL}}$ (Embeddable Common Lisp) are examples 
of scripting platforms that may be distributed in source-code fashion alongside host applications.

If a more minimal scripting environment is sufficient, $\color{#365450}{\mathrm{\large{}DogLeash}}$ allows programmers to build a 
scripting framework that is tightly integrated with other components in an 
Executable Research Object.  Here is a summary of some features and techniques.

**_C++ Interop_**

The first issue is exposing $\color{#365450}{\mathrm{\large{}C++}}$ procedures/methods to the script runtime.  The point here is that 
arguments are (at first) encoded in generic containers such as $\color{#365450}{\mathrm{\large{}QVariant}}$ or $\color{#365450}{\mathrm{\large{}QStringList}}$ 
(assuming we are working in a $\color{#365450}{\mathrm{\large{}Qt}}$ environment).  We need to convert these to local 
variables that get passed on the stack (or alter the stack some other way -- $\color{#365450}{\mathrm{\large{}AngelScript}}$ actually 
employs inline assembly code).  This seems like an impasse because we do not know the arguments' 
types ahead of time.  There is a workaround, however -- even without heavy introspection and 
dependencies such as $\color{#365450}{\mathrm{\large{}LLVM}}$ -- which can be illustrated with code adopted from 
}}$rpclib}}$ ([github.com/rpclib/rpclib](https://github.com/rpclib/rpclib)):


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
wrapper all of which have the same type (here using $\color{#365450}{\mathrm{\large{}QStringList}}\text{)}$.  There's a little more work 
to do, particularly to handle return values (plus maybe exceptions and pointer-to-members), but this is the basic idea.

We need a different technique for dynamically loaded libraries, however, because in that case we 
*don't* have signatures at compile time, so no `_func_traits` or `tuple_element`.  However, we 
can handle many or most functions that might be exposed for a data set.  Typically these 
fit familiar patterns that can be summarized with a compact code.  For instance, use numbers 
like 1, 2, 4, 8 for integers of different sizes.  Then a pair of 4-byte arguments with no return 
could get a code like $\color{#365450}{\mathrm{\large{}440}}$, and a wrapper constructured for every procedure with that kind of 
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
selected via a string of $\color{#365450}{\mathrm{\large{}switch}}$ statements: one for the arg count, next for the arg1 type 
(e.g., 1, 2, 4, or 8), next the arg2 type, etc.  Those $\color{#365450}{\mathrm{\large{}switch}}$es would work off of digits in 
the signture "code" (like 440) so that registering even an $\color{#365450}{\mathrm{\large{}.so}}$ runtime procedure 
would take only a single numeric code (which is simpler than how registering works 
in $\color{#365450}{\mathrm{\large{}ECL}}$ or $\color{#365450}{\mathrm{\large{}AngelScript}}\text{)}$.


**_Signature Codes_**

The problem with this technique is that only a relatively limited set of signatures can be 
supported -- a compilation unit can have only so many $\color{#365450}{\mathrm{\large{}switch}}$ cases.  $\color{#365450}{\mathrm{\large{}DogLeash}}$ tries 
to extend the range of available procedures by employing a more indirect signature-code 
mechanism.  Note that the count of signature patterns is affected by the number 
of distinct types a function takes as parameters.  For instance, if all arguments have 
the same type, then the only thing that varies is the number of parameters, so there's a 
maximum of say 10 $\color{#365450}{\mathrm{\large{}switch}}$ cases $\text{(}\color{#365450}{\mathrm{\large{}Qt}}$'s meta-object system, for $\color{#365450}{\mathrm{\large{}QObject}}$ subclasses, 
recognizes up to 10 arguments).  If there are two types, then a variety of argpack-sizes 
can be covered by bit vectors (on for one type and off for the other).  It's only with three 
or more types that you get potentially complex dispatch trees, but you're also problably 
not going to get a lot of *repetition*.  Suppose you have exactly three arguments of 
three different types: each signature is then a permutation of three elements, of which 
there are only six, plus $\color{#365450}{\mathrm{\large{}switch}}$ cases for the types involved.

By "types" here I mean any collection of binary-compatible types: we can cast a function-pointer 
to a generic signature based on unsigned integers, for example.  The actual procedures 
might take signed integers instead, or $\color{#365450}{\mathrm{\large{}enum}}$ values, but can be correctly called via 
that partially-type-erased pointer instead.  In any case, $\color{#365450}{\mathrm{\large{}RedPatch}}$ has 
sample code representing dispatch-tables sufficient for most signatures one might 
need to expose from a library.

**_Language Server Protocol_**

The $\color{#365450}{\mathrm{\large{}Language Server Protocol}}$ $\text{(}\color{#365450}{\mathrm{\large{}LSP}}\text{)}$, developed by Microsoft, is a tool through which 
code editors and Integrated Development Environments $\text{(}\color{#365450}{\mathrm{\large{}IDE}}\text{s}$) communicate 
with external programs that play the role of code assistants, 
offering hints, information on data types and function signatures, code completion 
suggestion, etc.  For example, $\color{#365450}{\mathrm{\large{}Clangd}}$ is the preeminent Language Server 
for $\color{#365450}{\mathrm{\large{}C++}}$.

The $\color{#365450}{\mathrm{\large{}LSP}}$ model is flexible, and a variety of different software components 
can be useful Language Servers.  It is not necessary to fully parse 
source files, as $\color{#365450}{\mathrm{\large{}Clangd}}$ does; depending on the language and the server 
it may be possible to build more limited views onto source code 
which still can be helpful for certain $\color{#365450}{\mathrm{\large{}LSP}}$ requests.  Language 
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
dispatch.  Continuing the above $\color{#365450}{\mathrm{\large{}RPC}}$ example, functions' 
names and signature codes are the kind of information that could be 
exposed via metadata files.

By way of illustration, the following is an example of how 
to use $\color{#365450}{\mathrm{\large{}LLVM}}$ $\color{#365450}{\mathrm{\large{}IRBuilder}}$ code, generated by Google $\color{#365450}{\mathrm{\large{}AI}}$:

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
to one of the dispatch protocols outlined above.  Let's imagine wrapping the $\color{#365450}{\mathrm{\large{}IRBuilder}}$ 
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

With very few changes (maybe the last line becomes some sort of $\color{#365450}{\mathrm{\large{}call}}$ instruction instead) this might be 
almost identical to VM instructions for an $\color{#365450}{\mathrm{\large{}FFI}}$-style call intead.

The point is that a standardized type-metadata format could be used simultaneously both to 
feed information to Language Servers and to enable Script Hosting (and, by 
extension, query evaluation).  That's the rationale behind $\color{#365450}{\mathrm{\large{}DogLeash}}$ as a Language Server 
*and* Script Host (the "leash") and the basis for the $\color{#365450}{\mathrm{\large{}Qynviper}}$ 
modules mentioned above.

<a id="sample-documents-raised"></a>

## Sample Documents

The following are examples of my own publications (not in chronological order) 
developed with $\color{#365450}{\mathrm{\large{}DogLeash}}$ code in some iteration.

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
linguistic samples, and employed $\color{#365450}{\mathrm{\large{}DogLeash}}$ to 
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
links to $\color{#365450}{\mathrm{\large{}PDF}}$ documents illustrating some $\color{#365450}{\mathrm{\large{}DogLeash}}$ features.

###  Projects Involving Data and/or Code Packages

1.  CSV and SVG Integration:  This project coincided with the five-year cycle 
for the Environmental Protection Agency's "Hazard Mitigation" plan.  As part 
of this $\color{#365450}{\mathrm{\large{}EPA}}$ program, states and counties are required to submit documentation 
for how they identify and address environmental dangers in their 
communities.  Here, I used $\color{#365450}{\mathrm{\large{}DogLeash}}$ tools to address both environmental 
data and Zoning/Land Use ordinances so as to explore the connections 
between environmental health and urban development.  Part of this 
project involved extending a New York City tool called 
}}$ZoLa}}$ (for Zoning and Land Use), which was created by 
NYC Planning Labs but openly shared in the hopes that 
other jurisdictions adopt the same technology.  Other 
data sourecs came from the $\color{#365450}{\mathrm{\large{}EPA}}$ "Toxic Release Inventory" $\text{(}\color{#365450}{\mathrm{\large{}TRI}}\text{)}$ 
data set, which publishes data files identifying reported 
contamination incidents by geographic coordinates, and 
has been studied for publications such as the NYC "Environmental Justice" 
$\text{(}\color{#365450}{\mathrm{\large{}EJNYC}}\text{)}$ report and mapping tool.  My goal was to examine how 
data sets such as $\color{#365450}{\mathrm{\large{}TRI}}$, along with environmental-impact 
data presented by states or private organizations, could be cross-referenced 
with Zoning and Land Use maps.  Demonstration code included $\color{#365450}{\mathrm{\large{}CSV}}$ deserializers 
to handle to complex $\color{#365450}{\mathrm{\large{}TRI}}$ data structures, that were hierarchical 
more than tabular in nature but used $\color{#365450}{\mathrm{\large{}CSV}}$ as a rough serialization tool, 
as well as native-compiled $\color{#365450}{\mathrm{\large{}GUI}}$ components based on $\color{#365450}{\mathrm{\large{}OpenStreetMap}}$ 
for $\color{#365450}{\mathrm{\large{}GIS}}$ displays.

    During this work I identified a series of errors with the $\color{#365450}{\mathrm{\large{}TRI}}$ encoding and 
documentation, so another layor of components implemented for this project 
involved mapping $\color{#365450}{\mathrm{\large{}TRI}}$-related $\color{#365450}{\mathrm{\large{}PDF}}$ files to $\color{#365450}{\mathrm{\large{}SVG}}$, so that I could 
superimpose annotations identifying the $\color{#365450}{\mathrm{\large{}TRI}}$ problems and 
how they could be corrected in code. 


2.  Annotated Legal Documents:  This was another project leveraging 
}}$PDF}}$-to-}}$SVG}}$ conversion.  The basic material for this project 
was a collection of legal documents that had been merged into a 
single file and then annotated to show patterns of 
behavior.  Applying techniques from ethnomethodology, the annotator 
designed a controlled vocabuly to insert terms functioning 
as "handles" into $\color{#365450}{\mathrm{\large{}PDF}}$ comment boxes.  I then implemented 
code which scanned these $\color{#365450}{\mathrm{\large{}PDF}}$ annotations and identified 
sub-documents which, according to the annotator, 
exhibited various patterns of communicative behavior.  I then 
split the larger $\color{#365450}{\mathrm{\large{}PDF}}$ into multiple subdocuments and mapped 
that content to hybrid $\color{#365450}{\mathrm{\large{}HTML}}$/}}$SVG}}$ pages, together with an 
online index that showed annotated classifications for 
each subdocument, plus page-by-page as well as document-by-document 
navigation for the linked pages.  The overall package was presented 
to a judge as a user-friendly alternative to submitting the 
original manuscript as a monolithic item of evidence. 

3.  Building a Book's Second Edition:  This project involved merging 
additional material added by the authors into a book they had 
initially published in 2005.  We built an in-house full $\color{#365450}{\mathrm{\large{}PDF}}$ 
of the new edition that mimicked the style and layout of the 
preparatory manuscripts shared by the publishers.  By cross-referencing 
the two versions, we were able to identify errors made on the 
publisher's end by copy editors and also fine-tune the new material.
Significant effort went into creating and updated index.  Special 
}}$DogLeash}}$ tools laid a foundation for custom $\color{#365450}{\mathrm{\large{}GUI}}\text{s}$ whose goal 
was to compare the first- and second-edition manuscripts to 
ensure that all previous index entries were migrated to the 
updated book, as well as creating new index material in the 
pbulisher's desired metadata format.

4.  Examining Biomedical Software:  During the Covid pandemic, 
I wrote the text for a book called _Innovative Data Integration and Conceptual 
Space Modeling for COVID, Cancer, and Cardiac Care_ (Elsevier, 
2022).  This book included a detailed examination of certain 
software components — such as the Cancer Phenomics Toolkit $\text{(}\color{#365450}{\mathrm{\large{}CapTk}}\text{)}$, 
}}$IQmol}}$ molecular visualization software, $\color{#365450}{\mathrm{\large{}cytolib}}$ for flow cytometry, 
}}$medInria}}$ and $\color{#365450}{\mathrm{\large{}Semantic PACS}}$ (Picture Archiving and Communication System), 
and the Cancer Bioinformatics Grid $\text{(}\color{#365450}{\mathrm{\large{}caBig}}\text{)}$ Image Annotation Toolkit — 
bioinformatics file formats (and their deserialization/analytic libaries), 
and collaborative projects (such as $\color{#365450}{\mathrm{\large{}caBig}}$'s "Digital Model Repository" 
and the $\color{#365450}{\mathrm{\large{}CORD-19}}$ archive for Covid research).  $\color{#365450}{\mathrm{\large{}CORD-19}}$ (the 
COVID-19 Open Research Dataset) grew to encompass over 400,000 open-access 
articles focusing on SARS-COV-2 and related topics (including the original 
SARS epidemic and Coronavirus biology in general) with freely-available 
full-text encoding.  The goal of $\color{#365450}{\mathrm{\large{}CORD-19}}$ was to help scientists in 
different areas addressing the pandemic (viral morphology, infectious 
mechanisms, diagnostics, clinical treatment assesment, vaccine development, 
genomics, variants/mutations, epidemiology, long-term effects) discover 
resources or research that could augment their own work, helping 
piece together the Covid puzzle.  Unfortunately, much of $\color{#365450}{\mathrm{\large{}CORD-19}}$'s
implementation depended on $\color{#365450}{\mathrm{\large{}PDF}}$ text extraction, which 
yielded errors and limitations I analyzed in the Elsevier book.
The $\color{#365450}{\mathrm{\large{}CORD-19}}$ curators (from Allen Institute for AI) were open about these problems and 
even issued a "call to action" requesting publishers to 
develop and adopt more rigorous text-encoding 
methods:

    >   Though the full text of many scientific papers are available to researchers through $\color{#365450}{\mathrm{\large{}CORD-19}}$, a number of challenges prevent easy application of $\color{#365450}{\mathrm{\large{}NLP}}$ and text mining techniques to these papers. First, the primary distribution format of scientific papers — $\color{#365450}{\mathrm{\large{}PDF}}$ — is not amenable to text processing. The PDF file format is designed to share electronic documents rendered faithfully for reading and printing, and mixes visual with semantic information. Significant effort is needed to coerce $\color{#365450}{\mathrm{\large{}PDF}}$ into a format more amenable to text mining, such as $\color{#365450}{\mathrm{\large{}JATS}}$ $\color{#365450}{\mathrm{\large{}XML}}$, $\color{#365450}{\mathrm{\large{}BioC}}$, ... or $\color{#365450}{\mathrm{\large{}S2ORC}}$ $\color{#365450}{\mathrm{\large{}JSON}}$ ... [W]e can still benefit from better $\color{#365450}{\mathrm{\large{}PDF}}$ parsing tools for scientific documents. As a complement, scientific papers should also be made available in a structured format like $\color{#365450}{\mathrm{\large{}JSON}}$, $\color{#365450}{\mathrm{\large{}XML}}$, or $\color{#365450}{\mathrm{\large{}HTML}}$.

    Hopefully $\color{#365450}{\mathrm{\large{}DogLeash}}$ can contribute to this initiative. 

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












