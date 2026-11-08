
# SenPac : Subprofile Engineering for Publication-Anchored Code Libraries

This branch is intended to serve as an introduction to the proposed 
$\color{#a65450}\mathrm{OS4OA}$ (Open Source for Open Access) working group 
at $\color{#a65450}\mathrm{Force11}$ 
(which is &ldquo;A global community dedicated to improving scholarly 
communication, research practices, and knowledge sharing&rdquo;: 
<https://force11.org/>).  Here is the core language from that proposal:

>One mission for the proposed WG is to present and evaluate OS components that can make OA authors more productive.  Other initiatives already focus on how FOSS supports OA via infrastructure and tooling.  But this WG also addresses the question one step further: how can tools for publication development, view, indexing, and search engines be modified to counter biases against "OS&OA" (Open Source and Open Access)?  How to model the contribution and originality of OS&OA projects whose merit is incompletely captured via each paradigm in isolation (plus peer review, 
impact factor, and other metrics)?  How to amplify the visibility of OS&OA-principled research?
>
>The WG will examine platforms that can generically be called "Publication-Ancored" code libraries: Executable Research Objects/Articles, 
Research Compendium/Artifact, Reproducible Package, Open Science Capsule, "Whole Tales", StoryMaps, Computational Canvas.  The key detail is a kind of co-equal relationship between an Anchoring Publication and a Code Library (Pac/Eq: Publications and Code as Co-Equal).  The publication itself is a fully-developed unit of scholarly research (not just an overview or documentation); and the code library is intrinsic to the research contribution (not just supplemental materials or raw files satisfying Data Availability requirements).  Conventional tooling is not able to properly address both sides of this co-equal relationship (note that existing indexing algorithms target text or code but not both).
>
>When publications and code are &ldquo;co-equal&rdquo; then ignoring a research paper's 
role as a scholarly product diminishes assessment of the library, but failure to 
properly index and model the library hinders the Findability of the publication.


Note that _code_ &ldquo;indexing&rdquo; here need not be as granular as in
technical contexts such as the Language Server Protocol (e.g., need 
not entail a full $\color{#a65450}\mathrm{AST}$ parse).  For 
example, any tooling consuming a code index can focus on details 
specifically relevant to those reading the publication, such as: 
how do I run an analysis or simulation or otherwise reproduce a reported 
finding?  Or: can I see in code where a term, formula, scalar unit, algorithm, etc. is modeled or implemented?  Such info might come from inline code annotations or separate files, like with External $\color{#a65450}\mathrm{XML}$ Documentation.

Simultaneously, _text_ &ldquo;indexing&rdquo; under the 
$\color{#a65450}\mathrm{Pac{\small{/}}Eq}$ idea 
is distinct from word-vector-optimized indexes for Academic Search Engines, 
although better use of code-library metadata could certainly improve 
engines' accuracy and false-positive/false-negative 
percentages.  Components relevant to $\color{#a65450}\mathrm{SenPac}$ can 
leverage text indexes in multiple ways, including pre-publication document 
prep, text/code/data reuse, Text Mining, and $\color{#a65450}\mathrm{FAIRsharing}$ 
(Findable, Accessible, Interoperable, Reusable) in general.

---

## Overview


For this repository, &ldquo;Publication-Anchored Code Libraries&rdquo; is a 
generic phrase referring to various resource models synthesizing aspects 
of traditional academic publishing and code/data repositories 
as represented by github, Open Science, data sets hosts, etc.  Such hybrid 
resources may have more specific forms 
(such as &ldquo;Executable Research Objects&rdquo; and others mentioned 
above).  But the 
overarching $\color{#a65450}\mathrm{SenPac}$ model 
assumes two key details:

1. There is a main publication file that &ldquo;anchors&rdquo; a code and/or data 
library/repository.  The anchor's role is more substantial than just documenting 
or summarizing the libary; it should be a primary source for describing research 
methods, findings, and theoretical assumptions.  The publication may or 
may not also be submitted to a peer-reviewed journal, book series, 
or similar venue, but 
it should _a)_ be included directly in the code libary as a preprint 
or via an Open Access license; and _b)_ have formatting, 
annotations, and metadata consistent with academic papers, such as a persistent 
Document Object Identifier and encoding suitable for ingestion by 
scholarship indexers ($\color{#a65450}\mathrm{CORE}$, 
$\color{#a65450}\mathrm{BASE}$, Semantic Scholar, and so forth).
 
2. The surrounding code library is an intrinsic part of the publications' 
content and originality; it is not just Supplemental Materials 
or raw files satisfying Data Availability requirements.  Code libraries 
offer alternative routes for findability/discoverability 
than relying solely on peer review or academic indexing.  Embedding 
manuscripts in code repositories is therefore one technique for 
researchers to disseminate their work while remaining independent 
from mainstream/commercial scientific institutions.  On the other 
hand, sustaining that independence should not lessen the 
quality of publications themselves (even just in those aspects 
specific to being a computational artifact, like 
queryability and code interop).

Actually, the technological quality of publications can 
be _improved_ by authors who bring a wider repertoire 
of programming techniques than employed by commercial 
publishers.  The digital infrastructure engineered even by 
the most prestigious houses is distressingly limited 
from a software-development point of view. 

The phrase &ldquo;Publications and code as co-Equal&rdquo; 
($\color{#a65450}\mathrm{PacEq}$) captures the paradigm 
embraced by $\color{#a65450}\mathrm{OS4OA}$ and $\color{#a65450}\mathrm{SenPac}$.
And also the difficulty: existing technology rarely balances 
$\color{#a65450}\mathrm{OS}$ and $\color{#a65450}\mathrm{OA}$ on equal 
terms.  There is therefore a structural bias against 
$\color{#a65450}\mathrm{OS&OA}\color{black}$ 
resources which may not be evident 

---

## Manuscript Representation

$\color{#a65450}\mathrm{SenPac}$ assumes that the Anchoring Publication 
is provided via machine-readable representations as well as 
human-readable (canonically $\color{#a65450}\mathrm{PDF}$) 
formats.  For discussion, assume that this representation is 
based on $\color{#a65450}\mathrm{JATS}$ $\color{#a65450}\mathrm{XML}$ 
(perhaps with personal extensions), the currently-dominant 
standard.  Apart from a (relatively small) set of $\color{#a65450}\mathrm{JATS}$ 
semantic tags, authors adopting &ldquo;Compatibility Models&rdquo; can 
freely incorporate tags and/or attributes from other (data- more that 
document-oriented) standards, such as $\color{#a65450}\mathrm{NIEM}$ 
(National Information Exchange Model), $\color{#a65450}\mathrm{OMOP}$ 
(Observational Medical Outcomes Partnership), $\color{#a65450}\mathrm{MIBBI}$ 
(Minimum Information for Biological and Biomedical Investigations), 
$\color{#a65450}\mathrm{IFC}$ (Industry Foundation Classes),
$\color{#a65450}\mathrm{SciData}$ 
(<https://pmc.ncbi.nlm.nih.gov/articles/PMC5064921>), and many others.
In the anchoring manuscript authors could adopt such tags to 
annotate/surround sentences, keywords/phrases, 
special symbols and character sequences, citations/references, 
section titles, and so on. 

Those same vocabularies may then be reused within the code library, 
to annotate classes (and other datatypes), methods/procedures, 
input/output parameters, data records, scientific units 
(e.g., as properties of function parameters) and 
their interconversions, etc.   The reuse of tags/annotations in 
both textual and source-code environments engenders 
capabilities like

* Cross-referencing &ndash; jump from data visualization to achors in a $\color{#a65450}\mathrm{PDF}$ or vice-versa

* Running code &ndash; launch code-library procedures from the $\color{#a65450}\mathrm{PDF}$ viewer

* Document prep &ndash; prior to publication, segments of a manuscript that specifically present technical concepts, methods, or data stand out in importance for double-checking content, proofreading, fixing errors, or custom typesetting conventions

* Reuse as source material &ndash;  Future scientists citing/incorporating the 
publication may benefit from semantic tags that accelerate searching for specific 
technical language and discussions

* Highlighting &ndash;  The $\color{#a65450}\mathrm{Semantic Reader}$ 
from $\color{#a65450}\mathrm{Semantic Scholar}$/Allen Institute for 
$\color{#a65450}\mathrm{AI}$ has a 
Goal/Method/Result &ldquo;skimming&rdquo; feature that overlays colored highlights 
on $\color{#a65450}\mathrm{PDF}$ text ranges.  A $\color{#a65450}\mathrm{PDF}$ viewer 
could in principle implement a visually similar feature that 
identifies ranges from author-generated semantic tags rather than $\color{#a65450}\mathrm{AI}$.

* Search Engines &ndash;  Future indexers that are programmed to ingest semantic 
annotations could likewise read associated code libraries for 
potential inclusion in search results and quantification of a project's 
relevance to search terms and concept vectors.


---

## &ldquo;Subprofile Engineering&rdquo;

Most representation formats have an extension mechanism.  For 
example, $\color{#a65450}\mathrm{JATS}$ has Compatibility Meta Model, 
$\color{#a65450}\mathrm{RO}\text{-}\mathrm{Crate}$ has 
Profiles, and $\color{#a65450}\mathrm{NIEM}$ has 
$\color{#a65450}\mathrm{IEPD}\color{black}s$.  $\color{#a65450}\mathrm{SenPac}$ 
envisions that Anchoring Publications and archives will often 
combine multiple extensions/profiles into project-specific 
syntheses (hence _sub_ profiles).  The synthesis could 
be driven by one (or both) of two factors:

1. The project is interdisciplinary, or in general combines vocabularies 
representing two different semantic domains, perhaps within 
the same technology &mdash; two $\color{#a65450}\mathrm{RO}\text{-}\mathrm{Crate}$ profiles, 
two $\color{#a65450}\mathrm{XML}$ tag suites, etc.

2. The project recognizes vocabulary elements sourcing from different 
technologies that rarely interoperate, such as scientific 
data repositories and Electronic Health Records/Electronic Medical Records.

With respect to (2), only a fraction of established standards 
were explicitly formulated for academic publishing.  The key 
modern example is $\color{#a65450}\mathrm{JATS}$, but 
$\color{#a65450}\mathrm{JATS}$ itself is only tangentially 
a semantic tagging/annotation language.  For hosting 
scientific data, $\color{#a65450}\mathrm{RO}\text{-}\mathrm{Crate}$, 
$\color{#a65450}\mathrm{NetCDF}$ and 
$\color{#a65450}\mathrm{HDF5}$ are common examples.

But many 
data-representation formats are designed for pragmatic institutional 
use rather than academic research.  In medicine, for instance, 
$\color{#a65450}\mathrm{FHIR}$ Fast Healthcare Interoperability Resources, 
$\color{#a65450}\mathrm{OMOP CDM}$ 
(Observational Medical Outcomes Partnership &mdash; Common Data Model), 
$\color{#a65450}\mathrm{DICOM SR}$ 
(Digital Imaging and Communications in Medicine &mdash; Structured Reporting), 
or $\color{#a65450}\mathrm{OCL}$ 
(Open Concept Lab) are specifications intended for 
storing and communicating $\color{#a65450}\mathrm{EHR}$/$\color{#a65450}\mathrm{EMR}$ 
records and similar clinical data.  Similarly, $\color{#a65450}\mathrm{NIEM}$ 
is an important standard for legal and governmental data, and 
$\color{#a65450}\mathrm{IFC}$ systematizes information for 
architectural, engineering, and construction 
contexts.  Similarly, $\color{#a65450}\mathrm{GIS}$ (Geographic Information System) 
&ldquo;attribute layers&rdquo; are important for civil 
engineering, government (e.g., Zoning and Land Use ordinances), 
and any domain whose information includes 
entities that could be mapped to latitude/longitude coordinates.

In general, data for scholarly research may be acquired within 
scientific institutions themselves &mdash; as with controlled 
experiments  &mdash; but there are also many governmental/external 
information sources which have distinct models and 
protocols.  An author who intends to republish portions of 
publicly available data sets from outside academia 
usually needs to bridge structural gaps between 
academic and non-academic representations.

Since there are literally billions of potential subject-area combinations 
for interdisciplinary research, a comprehensive 
&ldquo;Controlled Vocabulary&rdquo; might have to be 
customized for each research project.  As examples 
(including ones cited on this repository's 
$\underline{\color{#3e2a47}\mathrm{\small{}RedPatch}}$ branch) &mdash; 

* Correlating carcinogens and cancer rates involves 
$\color{#a65450}\mathrm{GIS}$-coded environment 
data such as the $\color{#a65450}\mathrm{EPA}$ &ldquo;Toxic 
Release Inventory&rdquo;; Cheminformatics about 
individual substances, such as $\color{#a65450}\mathrm{PDB}$ 
(Protein Data Bank) files; and anonymized 
$\color{#a65450}\mathrm{EHR}\color{black}/\color{#a65450}\mathrm{EMR}$ 
records

* Neuroimaging has been used to study substance-abuse 
disorders, combining image data/annotations with 
case histories, patient narratives, and sociodemographic info

* Analysis of foster care and child-welfare outcomes may draw 
from disparate $\color{#a65450}\mathrm{IEPD}\color{black}s$, or aggregate 
reporting standards, such as 
National Electronic Interstate Compact Enterprise 
($\color{#a65450}\mathrm{NEICE}$), 
National Youth in Transition Database 
($\color{#a65450}\mathrm{NYTD}$), and 
Adoption and Foster Care Analysis and Reporting 
System ($\color{#a65450}\mathrm{NYTD}$), plus 
legal and medical documents

* Social Determinants of Health ($\color{#a65450}\mathrm{SDoH}$) 
research synthesizes medical, economic, and sociodemographic 
data in formats like $\color{#a65450}\mathrm{PRAPARE}$ 
(Protocol for Responding to and Assessing Patients' Assets, Risks, and Experiences)
and the $\color{#a65450}\mathrm{FHIR}$ &ldquo;Gravity&rdquo; project

&mdash; which are all community-health related.  The 
same point can be made vis-a-vis any interdisciplinary 
science or science/humanities collaboration.


**_Implementing Subprofiles_**

Informally these kinds of &ldquo;semantic&rdquo; syntheses may be 
embodied in lists of concepts, but computationally 
speaking the process by which informal terminologies become 
codified as reusable nomenclatures depends on 
specific protocol choices (plus the actual data format 
used &mdash; e.g., $\color{#a65450}\mathrm{XML}$ 
vs. $\color{#a65450}\mathrm{JSON}$ vs. 
custom grammars).  It is therefore appropriate 
to talk about subprofile _engineering_: developing 
project-specific machine-readable vocabularies is 
a nontrivial process.

There are, however, multiple practical benefits such as 

1. Pre-publication document prep: annotations can help 
authors, editors, proofreaders, indexers, typesetters, and 
compositors find specific manuscript locations &mdash; often, 
those governed by special vocabularies are also 
sites in a publication requiring extra editing, 
double-checking, special font/symbol handling, multiple 
citations, and so forth.

2. Tools helpful to those curating relatively small document 
collections or bibliographic databases, such as Open-Access journals, 
research collaborations, or independent scholars &mdash; 
semantic tags/annotations/metadata that are too granular 
for large-scale search engines may be 
fine for less heavily optimized indexes 

3. Document reuse  &mdash; if a publication becomes 
source material for a future manuscript, tags/annotations 
may help the new author utilize the prior 
work most effectively

4. Making documents interactive  &mdash; whereas $\color{#a65450}\mathrm{PDF}$ 
in particular has historically been a static format, new ideas such as 
Semantic Reader's (a $\color{#a65450}\mathrm{PDF}$ viewer from 
Semantic Scholar/Allen Institute for $\color{#a65450}\mathrm{AI}$) 
Goal/Method/Result &ldquo;skimming&rdquo; feature, with 
colored highlight overlays (mentioned above); and clickable glossaries or 
back-of-book indexes (even for short works like journal articles),
as well as dynamic graphics similar to Computational Notebook 
cells, are all possibilities for a more dynamic/interactive 
reading experience.

Moreover, (4) considers only _intra_ document interactive features. 
Pairing publications with code and data introduces 
entirely new forms of interop via multi-modal cross-references.

**_Interop between document viewers and other code-library components_**

Here are just a few examples: 

* Consider $\color{#a65450}\mathrm{XYZ}$ to latitude/longitude 
conversion ($\color{#a65450}\mathrm{XYZ}$ is x/y/zoom, a geospatial coordinate system).  We could ask: where's the first sentence in the publication where $\color{#a65450}\mathrm{XYZ}$ is defined?  We could also ask: find the procedure in the code library that takes $\color{#a65450}\mathrm{XYZ}$ input and generates an equivalent lat/lon pair.

* Consider region-of-interest feature-vector profiles for medical imaging.  We could ask: list the distinct Texture Segmentation methods reviewed in the publication (a list of sentences, citations, references, etc.).  We could also ask: list the methods and classes in the code library that implement Texture Segmentation algorithms. 

* Consider a linguistics paper that includes a list of sample sentences 
(a common technique is to use real or hypothetical sentences to 
demonstrate specific semantic, syntactic, or pragmatic claims). 
The analysis could be enhanced with dynamic graphics 
illustrating parsing (with phrase structure 
and/or dependency graphs), semantic frames, 
&ldquo;theta grid&rdquo; structures and thematic relations, 
morphosyntactic decomposition, and other technical details 
that readers might find helpful to visualize through 
moving, demonstrative illustrations. 

* Documents might embed links to audio, visual, digital maps, 
$\color{#a65450}\mathrm{3D}$ scenes, and other 
multimedia content.  With proper tooling these 
supplemental materials may be cross-referenced 
with one another (for instance, geotagging 
video frames) and back to the relevant 
sentences/paragraphs in the Anchor Publication.

**_Indexing text, code, and data_**




 




 











