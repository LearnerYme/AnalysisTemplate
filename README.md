# Analysis Template

Author: Yige Huang

Date: 28.02.2024

Version: 2.0

## Quick start

This template is a simple example of using CMake to build executable with `AnalysisTree` and some other modules (like `IdxConstants`, `MultiplicityTool` and `DuplicateRemover`).

1. Modify `src/AnalysisTemplate.cpp`

2. Put necessary modules into `src`, e.g. `src/IdxConstants`

3. Add module names into `CMakeList.txt`'s `ADD_TOOLS`

4. Run `./install.sh`

5. If you want to clean the folder, run `./install.sh uninstall`

## Patch Note

* 28.02.2024 by yghuang v2.0:

> Example with 3 modules.

* 21.02.2024 by yghuang v1.0:

> First version.
