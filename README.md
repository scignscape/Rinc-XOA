
# Rinc-XOA : Research in nonprofit contexts - Executable Open Access

---

### Overview

In publishing, Diamond (`DiamondOA`) is the most complete Open Access model, with no fees either for authors (i.e., Article Processing Charges (`APC`s)) or readers (i.e., article paywalls).  The work needed to prepare manuscripts for publication is either performed on a volunteer basis or supported by "Diamond Open Access Funds", which are more prevalent in the European Union than the United State.

Meanwhile, Executable Research Objects (`ERO`s) are one form of Research Object/data set guided by data transparency and `FAIRsharing` (Findable, Accessible, Interoperable, Reusable) principles.  Research Objects in general may include multiple forms of digital assets (text, code, raw data files, and perhaps multimedia content) which can present challenges for in-depth usage.  An *Executable* Research Object in particular provides a single Research Application that serves as an entry point or overarching resource streamlining access to the variegated parts of a data publication.  In general, these Research Applications are standalone desktop-style programs which, when launched, will provide visual summaries and windows to manage data set records, as well as viewers for other media types (`PDF` documents, images, videos, digital maps, etc.).

For the current repository and siblings, Executable Open Access (`XOA`) designates a synthesis of these two paradigms.  Most FAIRsharing projects, to be sure, are Open Access by default because they are hosted on free services such as Open Science Framework (`OSF`) or Dryad -- often linked to publications via "Data Availability" or "Supplemental Materials" sections on articles' landing pages (which also have abstracts, bibliographies, and so forth): there is no such thing as a "dataset processing charge".  Nonetheless, `ERO`s are most productive when they include complete version of associated research articles -- both in human-readable (e.g., `PDF`) and machine-readable (e.g., `JATS` `XML`) formats, which requires that the entire package be governed by a `DiamondOA` licence.  Moreover, aggregating disparate dataset materials into an overarching Research Application requires additional programming that could potentially be supported by `DiamondOA` funds or similar initiatives.  In short, the `ERO` and `DiamondOA` paradigms are sufficiently interrelated/overlapping that each may help promote the other.

`Rinc-XOA` (this repository) has a sibling repo called `DogLeash` (Diamond Object Grid - Language Server and Script Host), at [github.com/ScignScape/DogLeash/](https://github.com/scignscape/DogLeash/) which holds most of the actual code.  This code base is intended to provide tools and templates for Executable Research Objects.  `DogLeash` provides several "modules" for specific subject areas and implementation requirements, such as Medical Imaging, Geographic Information Systems, and Compiler Extensions.  A `Rinc-XOA` project can include any modules relevant to its topic.


### Community Health Research Platform

As a concrete example, I have grouped most of the `DogLeash` modules into a research "platform" called `RedPatch` (Research Objects - Diamond Open Access Targeting Community Health) which has its own branch in the current repository.  This code base leverages similarities between Electronic Health Records and Executable Research Object "microcomponents".  More specifically, at least for `DogLeash` an Executable Research Object is composed of multiple microcomponents which, in general, each provide one application window and present the user with information and/or graphics from a particular data profile, multimedia resource, or record source (data base, data set, `CSV`/`XML`/`JSON` file, etc.).  A good example of microcomponents would be displays showing a specific type of `EHR` form, or a single medical image alongside provenance, diagnostic, and annotation metadata.  In `DogLeash`, for each microcomponent there is typically a single `C++` class encapsulating the totality of information provided by one instance of the component, plus metadata about valid ranges/values for form fields and annotations on fields/enumerations in terms of standard vocabularies, such as Open Concept Lab.

Electronic Health Records and Medical Imaging is therefore a useful domain in which to implement concrete `DogLeash` components.  This does not mean that Executable Research Objects mimic on-site `EHR` forms used by health-care providers for their day-to-day operations; but special-purpose "research" forms may be developed that have similar presentation and terminological standards, and such forms in turn for the basis of open-access data sets.

### Publishing for Nonprofits

Supporting research in nonprofit contexts presents several distinct paradigms as compared with publishing workflows in traditional academic environments.  For one thing, authors are not necessarily affiliated with universities; they might instead be nonprofits' employees, volunteers, or independent researchers.  Outlets might not be conventional peer-reviewed journals or book series.  Some nonprofits act as their own miniature publishing houses; in other cases researchers may use platforms such as `github`, Open Science Framework, or Dryad.  A single document publication (e.g., the `PDF` of a research article) in this case may be just one file in a Research Object also containing source code and raw data files.

Insofar as publications are deployed with the same licences as code and data, they can be rigorously cross-referenced with sibling assets to an extent that is not feasible when documents are paywalled while data sets are not.  This use case is not well-supported by existing document-prep languages like `LaTeX` or `JATS`, so `DogLeash` provides its own input markup language, machine-readable text encoding, `PDF` annotation system, and custom `PDF` viewers (all of which may embedded direcly in Executable Research Objects as `C++` source files).  In this context, for example, articles are displayed via `PDF` files that may be viewed within `PDF` renderers built as part of the Research Object (i.e., Research Application) itself.

**_The "Diamond" Publishing Model_**

In contemporary academic publishing, the basic unit for sharing experience and ideas often is not a single manuscript, but rather a collection of files packaging variegated content-types, including `PDF` files for viewing documents, but also machine-readable text encoding, computer code, raw data, and statistical/graphics summaries.  These packages typically adhere to collaborative standards such as Research Object Bundles, Executable Research Objects, `FAIR`-sharing, and research-grid specifications for packages deposited on decentralized but searchable community networks.

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
such as customized `PDF` viewers specifically designed for a shared data package.

In brief, the diamond model is not only more ethical; it also permits technological 
enhancements that are impossible otherwise.  In particular, it becomes possible 
to implement a rigorous interop and query infrastructure that emcompasses both text manuscripts 
and dataset file


### Compiler Extensions

`DogLeash` Research Objects are assumed to be `C++` code libraries that compile to a single recognized 
Research Application (other utilities may be created as well, but someone using the data set should 
launch a single executable to access most or all available information and functionality).  In general, 
an Executable Research Object will include dataset-specific code for data deserialization, 
processing, analysis, visualization, and search capabilities.  Important procedures within this code 
should, as a rule, be exposed or wrapped in a remote-callable manner.

Assuming a Research Application is primarily implemented in `C++`, users should have the option of 
extending or fine-tuning this code without writing their own `C++` files that would need a separate 
compile/build step.  In short, Research Applications should have scripting capabilities.  Many 
scripting languages are possible, of course, but ideally the scripting framework should 
be compiled directly inside Research Object, rather than relying on an external 
interpreter.  Languages such as `LUA`, `AngelScript`, and `ECL` (Embeddable Common Lisp) are examples 
of scripting platforms that may be distributed in source-code fashion alongside host applications.

If a more minimal scripting environment is sufficient, `DogLeash` allows programmers to build a 
scripting framework that is tightly integrated with other components in an 
Executable Research Object.  Here is a summary of some features and techniques.

**_C++ Interop_**

The first issue is exposing `C++` procedures/methods to the script runtime.  The point here is that 
arguments are (at first) encoded in generic containers such as `QVariant` or `QStringList` 
(assuming we are working in a `Qt` environment).  We need to convert these to local 
variables that get passed on the stack (or alter the stack some other way -- `AngelScript` actually 
employs inline assembly code).  This seems like an impasse because we do not know the arguments' 
types ahead of time.  There is a workaround, however -- even without heave introspection and 
dependencies such as `LLVM` -- which can be illustrated with code adopted from the `RPC` library.

```

template<typename ...>





```










