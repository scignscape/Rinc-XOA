
# RedPatch : Research Objects - Diamond Open Access Targeting Community Health

RedPatch is Community Health-oriented research platform with C++ sublibraries related to Electronic Health Records, Medical Imaging, Geographic Information Systems, and Academic Publishing.

---

First, a disclaimer: the code linked from this branch originated with my own personal research project or ones I joined as a programmer and/or (data and text) editor.  There is no funding nor development team.  As such, this work is less polished than I would like, and all code should be considered prototype/experimental.  I appreciate anyone who actually browses this code, but in practice I may need to personally help interested users (on a volunteer bases) to adapt this code for their own projects, at least during this early stage (at least I HOPE this is just an early stage!).

So, RedPatch is the *early stages* of a Research Platform for Community Health.  It is part of a larger project that involves code supporting Diamond Open Access publishing in general, particularly Executable Research Objects that cross-reference documents with open-access data sets (integrated into a single package and, indeed, once compiled, into a single Research Application).

The underlying technology I have called "DogLeash" (Diamond Object Grid - Language Server and Script Host) which developed Executable Research Objects as collections of semi-autonomous modules.  RedPatch is one instantiation of this idea, combining several modules related to Community Health.  These modules are split between the DogLeash repository itself (for more general-purpose code) and this current branch.  There are five modules addressing these areas:


- Academic Publishing: document preparation and data integration
- Electronic Health Records -- including special-purpose records/forms that might be specifically used by Community Health researchers 
- Medical Imaging, to support researchers studying community-health providers in areas of medicine where imaging is important for diagnosis and treatment, such as Oncology, musculoskeletal interventions, and prenatal care
- Digital Maps to build, export, and visualize GIS data sets addressing community-health concerns such as disease outbreaks, epidemiology, Social Determinants of Health (SDoH), locations of health-care providers, and so forth,
- Environmental Factors: tools to study public-health implications of pollution, ecological degradation, contaminated water supplies, and similar civil-infrastructure concerns
 To be more specific, the modules include code that may be narrow in scope but could be adapted for other contexts.  For example, the EHR module is focused on AMPATH (Academic Model Providing Access To Healthcare) Forms but the implemented "native rendering techniques" could be used with other EHR systems.  Here is some concrete functionality representative of each of the aforementioned modules:
- 
- Electronic Health Records:   
  
