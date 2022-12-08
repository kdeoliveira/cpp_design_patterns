## DESIGN PATTERNS


### Shared Libs with Static lib
In case a static library is linked in a outer shared library, ensure that static lib is set the static to be Position Independent.
This is because .dll/.so are set to contain Positino Independent Code where the code can be placed in any location and its defined functions can be called regardless of its address.

- Shared_lib/:
```
add_library(MyShared SHARED myshared.cxx)
target_link_libraries(MyShared PRIVATE )
```

- Shared_lib/Static_lib
```
add_library(MyStatic STATIC mystatic.cxx)
set_target_properties(MyStatic PROPERTIES POSITION_INDEPENDENT_CODE)
```