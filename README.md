
# QPDF/SR : Development code for a Markdown&#10132;JATS&#10132;PDF/SR workflow

See this repository's $\color{#a65450}\mathrm{Paw/Prints}$ branch for more information about the 
goals for this specific workflow.  Note: $\color{#a65450}\mathrm{PDF/SR}$ stands for 
$\color{#a65450}\mathrm{PDF}$ Semantic Reflection.

Currently this branch holds a $\color{#a65450}\mathrm{Qt}$ $\color{#a65450}\mathrm{PDF}$ viewer 
based on qpdfview (<https://github.com/bendikro/qpdfview>).  For the moment there 
are only minor changes to the qpdfview code.  The $\color{#a65450}\mathrm{COPYING}$ 
file serves as qpdfview's license file.  $\color{#a65450}\mathrm{LICENSE\\_1\\_0.txt}$ 
governs any new code here.  Documents distributed for demo purposes are assumed 
to be free for fair use under the copyright of their author/creator.

It is recommended that users clone this code as a single branch:

```
mkdir QPDF-SR
cd QPDF-SR
git clone -b QPDF/SR --single-branch https://github.com/scignscape/Rinc-XOA.git ar

```
or replace `ar` with some other name for the top-level folder.


This code adds a separate `qpdf-unified` project file which bypasses 
the Qt Creator `subdirs` system.  Just open that one project 
to get the basic $\color{#a65450}\mathrm{PDF}$ functionality.  Note 
however that plugins will not be built.

The key dependencies are:

* $\color{#a65450}\mathrm{Qt}$

* A sufficiently up-to-date C++ compiler 
 (tested here with g++14)

* Poppler.  The project file assumes that Poppler is built from source and installed 
to a sibling folder of this branch's top-level folder, but that may not 
be necessary for all environments.  Note that Poppler itself has additional 
font-related dependencies.

While not strictly necessary, this project assumes that the viewer is compiled 
and launched from the $\color{#a65450}\mathrm{Qt}$ Creator $\color{#a65450}\mathrm{IDE}$.

The current code does not have any capabilities beyond qpdfview itself, 
but I intend to use it as a sandbox for looking at 
&ldquo;Semantic Reflection&rdquo; features such as

1. Examining accompanying code assets (e.g., Python scripts)

2. Embedding &ldquo;sidecar&rdquo; annotation via 
$\color{#a65450}\mathrm{AF}$ keys

3. Representing $\color{#a65450}\mathrm{CiTO}$ (Citation Typing Ontology) 
&ldquo;Citation Intent&rdquo; markup

4. Representing author &ldquo;endorsements&rdquo; of Open Source/Open Access 
cited resources

5. Representing Goal/Method/Result annotations similar to 
&ldquo;Skimming Highlights&rdquo; in Semantic Reader 
(<https://www.semanticscholar.org/product/semantic-reader>)

6. Dynamically calling code, to emulate Computational Notebooks

7. Enabling user-defined vocabularies to annotate both text and code 

8. Examining information about data sets and/or deserialized data records

9. Supporting extensible Markdown dialects with custom parsers

--- 

References for the two included research notes are 

* <https://zenodo.org/records/24165091>

* <https://zenodo.org/records/24194873>










