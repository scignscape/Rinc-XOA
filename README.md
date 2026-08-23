
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

In contemporary academic publishing, the basic unit for sharing experience and ideas often is not a single manuscript, but rather a collection of files packaging variegated content-types, including PDF files for viewing documents, but also machine-readable text encoding, computer code, raw data, and statistical/graphics summaries.  These packages typically adhere to collaborative standards such as Research Object Bundles, Executable Research Objects, `FAIR`-sharing (Findable, Accessible, Interoperable, Reusable), and research-grid specifications for packages deposited on decentralized but searchable community networks.

In the genre of open-access publishing, the "diamond" model indicates documents that 
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
such as customized PDF viewers specifically designed for a shared data package.

In brief, the diamond model is not only more ethical; it also permits technological 
enhancements that are impossible otherwise.


---


One hindrance to widespread adoption of both paradigms is that their documentations tend to gravitate toward general statements of principle or summarial specifications (such as Research Object Bundles or the RO-Crate framework) rather than substantial tools that help authors, scientists, and/or programmers actually implement Executable Open Access applications.  The sibling project ScignScape/DogLeash (Diamond Object Grid -- Language Server and Script Host) addresses this limitation by publishing compiler and IDE (Integrated Development) Extensions that can form the basis of XOA projects.  Technical discussion of these code libraries is provided through the DogLeash repository.

The DogLeash components are not specifically tied to a non-profit environment, except insofar a DiamondOA resources tend to be developed by nonprofits to begin with (either academic institutions or noncommercial projects specifically oriented to the Diamond ecosystem).  As a result, the current repository (Rinc-XOA) is set aside for tools or extensions to ScignScape/DogLeash that are specific to the nonprofit context.  This can include links to ScignScape applications as well as code components that could be useful for populating open-access data sets with information derived from nonprofit settings, which may utilize schema such as the Common Data Model for Nonprofits and/or require extra processing steps (e.g., depersonalization and other techniques to preserve personal privacy).

"ScignScape" -- Science Grid Nodes/Semantic Application Engine -- is also a neologism, describing a generic model wherein executable applications function as citeable resources alongside (and associated with) research publications.  In general, "semantic" applications in this sense will employ both dataset and code annotations and will declare explicit, granular cross-references to research publications.  Full-text searches against scientific/academic manuscripts may then be extended to XOA packages and vice-versa.  Code elements such as data types, record fields, units of measurement, coordinate systems, procedures' pre/post-condition contracts, and specific functions or algorithms (e.g., coordinate-transforms or deserialization grammars) are good candidates for semantic indexing.  So too are many GUI components, including individual controls (buttons, forms, display containers) as well as context menus, user-visible actions, and MVC (Model/View/Controller) style mappings between data types and GUI classes.  For robust desktop-style engineering, much of this information should be curated anyhow for documentation that helps users discover, for example, how to perform a specific action against a data set (e.g., calculate a statistical analysis or launch a simulation).  The idea behind ScignScape is that annotations and metadata may also be used to compile infosets that support full-text searches against application code following query protocols similar to those for text-document repositories.

To be more specific, the DogLeash repository includes a specification that enumerates multiple query protocols that compliant applications will support, both with respect to code, data, and text manuscripts.  Whether or not users choose to adopt this particular specification, hopefully it serves as an example of how code, text, and data can be unified into a single searchable compilation.  DogLeash provides the basic infrastructure for a query/scripting language, OTQR (Object/Text Query Runtime) that can implement the ScignScape protocol as customized for individual XOA applications.

Parts of the ScignScape protocol are directly adopted from the Language Server Protocol (LSP), which governs interop between IDEs and code libraries written in specific programming languages (i.e., there are LSP servers for many programming languages, such as Clangd or ccls for C++, and Palantir or Pyright for Python).  In general, ScignScape does not explicit address queries related to live code editing, but extends LSP with static code data directly relevant to source files implementing Executable Research Objects.  Again, please visit the ScignScape/DogLeash repository for more information.

At the same time, the ScignScape protocol also covers code-introspection capabilities utilizable for "semantic" applications as runtime script hosts.  In the ERO context, scripting can be used to fine-tune deserialization, GUIs, data analysis, and in general to expose project-specific data and functionality for researchers who want to reuse or reexamine published findings.  There are many similarities between a Language Server and a Script Host -- such as indexing function-signatures so that procedures may be identified by name -- but they serve somewhat different purposes.  Nonetheless, DogLeash introduces the concept of a "Language Server Infoset" that is compiled from code libraries and aggregates static metadata relevant for both Language Server and Script Host implementations.   

The design of Rinc-XOA and DogLeash assumes that most users will clone a specific branch of DogLeash, and Rinc-XOA is set aside for informative documents and "nonpublic" assets.  It is recommended that users do not clone the full DogLeash repository, which contains experimental and work-in-process code, but rather choose a single branch to use as a starting point for developing XOA software.  The branches include tools for working with image series, digital maps, PDF, JATS, and other multimedia resources that may be useful for XOA applications as well as compiler, parsing, and VM code.  
On *this* repository (Rinc-XOA), the "JATS-Con-demo" branch hosts demo code for my presentation at the JATS conference 2026).  The "CTG" branch ("Cognitive Transform Grammar") is essentially a repository version of the Research Object hosted on Open Science Framework at 
In conclusion, the following is a list of publications created with some version of DogLeash code.  Those that are *starred* are (at least in my opinion) technically relevant to DogLeash itself insofar as they address topics in compiler theory, type theory, or Software Language Engineering that motivate the DogLeash parsing, native-interop, and Virtual Machine strategies.  


