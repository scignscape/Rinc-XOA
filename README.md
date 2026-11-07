
# SenPac : Subprofile Engineering for Publication-Anchored Code Libraries

For this repository, &ldquo;Publication-Anchored Code Libraries&rdquo; is a 
generic phrase referring to various resource models synthesizing aspects 
of traditional academic publishing and code/data repositories 
as represented by github, Open Science, data sets hosts, etc.  Such hybrid 
resources may have more specific forms such as Executable Research Objects/Articles, 
Research Compendium/Artifact, Reproducible Package, Open Science Capsule, &ldquo;Whole 
&rdquo;, among others.   But the overarching $\color{#a65450}\mathrm{SenPac}$ model 
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
scholarship indexers (CORE, BASE, Semantic Scholar, and so forth).
 
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

Actually, the technological quality of publications can readily 
be _improved_ by authors who can bring a wider repertoire 
of programming techniques than employed by commercial 
publishers.  The digital infrastructure engineered even by 
the most prestigious houses is distressingly limited 
from a software-development point of view. 

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

* Running code &ndash; launch code-library procedures from the  &ndash;   viewer

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











