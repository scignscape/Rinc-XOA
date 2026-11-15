
# QPDF/SR : Development code for a Markdown->JATS->PDF/SR workflow

Note: $\color{#a65450}\mathrm{PDF/SR}$ stands for 
$\color{#a65450}\mathrm{PDF}$ Semantic Reflection.

See this repository's $\color{#a65450}\mathrm{Paw/Prints}$ branch for more information about the 
goals for this specific workflow.

Currently this branch holds a 
$\color{#a65450}\mathrm{LICENSE_1_0.txt}$ viewer based (almost entirely) on 
qpdfview (<https://github.com/bendikro/qpdfview>).  There 
are only minor changes to the qpdfview code.  The $\color{#a65450}\mathrm{COPYING}$ 
file serves as qpdfview's license file.  $\color{#a65450}\mathrm{LICENSE\_1\_0.txt}$ 
governs any new code here.  Documents distributed for demo purposes are assumed 
to be free for fair use under the copyright of their author/creator.

This code adds a separate `qpdf-unified` project file which bypasses 
the Qt Creator `subdirs` system.  Just open that one project 
to get the basic $\color{#a65450}\mathrm{PDF}$ functionality.  Note 
however that plugins will not be built.

The key dependencies are:

* $\color{#a65450}\mathrm{Qt}$

* A sufficiently up-to-date $\color{#a65450}\mathrm{C++}$ compiler 
 (tested here with $\color{#a65450}\mathrm{C++}$)

* Poppler.  The project file assumes that Poppler is built from source and installed 
to a sibling folder of this branch's top-level folder, but that may not 
be necessary for all environments.  Note that Poppler itself has additional 
font-related dependencies.

While not strictly necessary, this project assumes that the viewer is compiled 
and launched from the Qt Creator $\color{#a65450}\mathrm{IDE}$

The current code does not have any capabilities beyond qpdfview itself, 
but I intend to use it as a sandbox for looking at 
&ldquo;Semantic Reflection&rdquo; features such as

1. Examining accompanying code assets (e.g., Python scripts)

2. Embedding &ldquo;sidecar&rdquo; annotation via 
$\color{#a65450}\mathrm{AF}$ keys

3. Representing $\color{#a65450}\mathrm{CiTO}$ (Citation Ontology) 
&ldquo;Citation Intent&rdquo; markup

4. Representing author &ldquo;endorsements&rdquo; of Open Source/Open Access 
cited resources

5. Representing Goal/Method/Result annotations similar to 
&ldquo;Skimming Highlights&rquo; in Semantic Reader 
(<https://www.semanticscholar.org/product/semantic-reader>)

6. Dynamically calling code, to emulate Computational Notebooks

7. Enabling user-defined vocabularies to annotate both text and code 

8. Examining information about data sets and/or deserialized data records

9. Supporting extensible Markdown dialects with custom parsers










