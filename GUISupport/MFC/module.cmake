# only add this module if we are on a windows platform
if(WIN32)
  vtk_module(vtkGUISupportMFC
    DEPENDS
    vtkRenderingOpenGL
    vtkInteractionStyle
    EXCLUDE_FROM_WRAPPING
    )
endif()

