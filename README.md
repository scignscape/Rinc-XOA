
# RedPatch : Research Objects - Diamond Open Access Targeting Community Health

RedPatch is Community Health-oriented research platform with C++ sublibraries related to Electronic Health Records, Medical Imaging, Geographic Information Systems, and Academic Publishing.

---

First, a disclaimer: the code linked from this branch originated with my own personal research project or ones I joined as a programmer and/or (data and text) editor.  There is no funding nor development team.  As such, this work is less polished than I would like, and all code should be considered prototype/experimental.  I appreciate anyone who actually browses this code, but in practice I may need to personally help interested users (on a volunteer bases) to adapt this code for their own projects, at least during this early stage (at least I HOPE this is just an early stage!).

So, RedPatch is the *early stages* of a Research Platform for Community Health.  It is part of a larger project that involves code supporting Diamond Open Access publishing in general, particularly Executable Research Objects that cross-reference documents with open-access data sets (integrated into a single package and, indeed, once compiled, into a single Research Application).

---

## Overview

The underlying technology I have called "DogLeash" (Diamond Object Grid - Language Server and Script Host) which developed Executable Research Objects as collections of semi-autonomous modules.  RedPatch is one instantiation of this idea, combining several modules related to Community Health.  These modules are split between the DogLeash repository itself (for more general-purpose code) and this current branch.  RedPatch is comprised of six modules:


- Academic Publishing: document preparation and data integration

- Electronic Health Records -- including special-purpose records/forms that might be specifically used by Community Health researchers 

- Medical Imaging, to support researchers studying community-health providers in areas of medicine where imaging is important for diagnosis and treatment, such as Oncology, musculoskeletal interventions, and prenatal care

- Digital Maps to build, export, and visualize GIS data sets addressing community-health concerns such as disease outbreaks, epidemiology, Social Determinants of Health (SDoH), and locations of health-care providers (permanent or temporary/emergency)

- Environmental Factors: tools to study public-health implications of pollution, ecological degradation, contaminated water supplies, and similar civil-infrastructure concerns

- Compiler Infrastructure: Supporting programming tasks such as implementing new EHR forms for individual research projects

---

To be more specific, the modules include code that may be narrow in scope but could be adapted for other contexts.  For example, the EHR module is focused on AMPATH (Academic Model Providing Access To Healthcare) Forms but the implemented "native rendering techniques" could be used with other EHR systems.  Here is some concrete functionality representative of each of the aforementioned modules:

- Academic Publishing:  RedPatch incorporates the DogLeash GTagML module, which can be used to generate documents in a variety of formats, including PDF, LaTeX, and JATS-XML.  GTagML is optimized for creating publications that are cross-referenced with data sets in Executable Research Objects.  See the GTagML branch of DogLeash at [https://github.com/scignscape/DogLeash/tree/GTagML](https://github.com/ScignScape/DogLeash/tree/GTagML).

- Electronic Health Records: At present, this module is focused on a "Native Rendering Engine" for AMPATH forms.  In OpenMRS (Open Medical Record System) -- developed by AMPATH and used by Doctors Without Borders, Partners in Health, Care 2 Communities, and other NGOs/nonprofits -- AMPATH forms are internally stored as JSON configuration files that get converted to web pages via ReactJS.  This module provides an alternative rendering engine that, instead, maps the configurations to C++ classes to provide self-contained GUI components.  These classes could be run as isolated executable, or grouped into form libraries that collectively form customized EHR software, or embedded in host applications.  But in each case the form is a single desktop application window: there's no need for client/server separation, server processes, HTTP requests, or running the User Interface through a web browser.

    AMPATH forms are granularly annotated, particularly via Open Concept Library (OCL) concepts (which often cross-reference with other terminology standards, such as CIEL (Columbia International eHealth Laboratory), SNOMED, and ICD (International Classification of Diseases)).  Form fields and (for enumerative values)asasigned their possible values are assigned unique OCL identifiers, as are forms as a whole and their component sections.  These annotations are presevered via the Native Rendering Engine as C++ source annotations and GUI metadata.

    For reference and demonstration purposes, this module includes generated code for the 77 AMPATH Forms developed by Doctors Without Borders; other forms may be customized via the OpenMRS form builder.  The module's utilities can generate a C++ class from a JSON configuration file, and demo code shows how to perform these steps for each of the Doctors Without Borders form files.

- Medical Imaging: Most of the RedPatch code for diagnostic imaging is based on the C++ library DCMTK, one of the most widely used libraries for processing DICOM (Digital Imaging and Communications in Medicine) files.  RedPatch provides several programs that follow the same protocol as other DCMTK utilities, either invoked from the command line or called as ordinary C++ methods from host applications.  RedPatch code includes:

    &nbsp; &nbsp; &#x2192; dcm2cdm: Represent DICOM metadata in terms of the MI-CDM (Medical Imaging Common Data Model) proposal from OMOP (Observational Medical Outcomes Partnership).  OMOP-CDM embraces a tabular structure in contrast to standards such as FHIR (Fast Healthcare Interoperability Resources), which means that data object have to be packaged via OMOP-specific algorithms

    &nbsp; &nbsp; &#x25e6; dcm2ro: Construct Research Object components conformant to specifications such as RO-Crate.  This utility packages select DICOM image, image metadata such as GSPS (Greyscale Presentation State), and DICOM-SR (Structured Reporting) files into single resources using generic formats such as PNG and XML rather than DICOM-specific encoding.  The resulting files can be packages into Executable Research Objects and other dataset protocols.

    In addition to these utilities, RedPatch provides sample code to show how the utilities and AMPATH native-rendered forms may be embedded in DICOM/PACS (Picture Archive and Communications System) software.  More spefically, RedPatch publishes plugins to medInria, and open-source, full-featured C++ DICOM client with an emphasis on advanced image-processing capabilities.

- GIS and Digital Maps: 



