[python]: https://github.com/python/cpython "github-cpython"
[lua]: https://github.com/lua/lua "lua"
[jsoncpp]: https://github.com/open-source-parsers/jsoncpp "jsoncpp"
[tinyxml]: https://github.com/icebreaker/TinyXML "tinyxml"
[visualstudio]: https://www.visualstudio.com/ "Visual Studio"

Z-Editor
=====

Library Requires
-----
The requires libs:(all the address is connected to github)
- [python]
- [lua]
- [jsoncpp]
- [tinyxml]

You need to push these librays to ./ZScratch/lib , and rename them, like:
        ZScratch/lib
            ├-python
            ├-lua
            ├-jsoncpp
            └-tinyxml
And you need to copy the include files to these forders.
The library files have already exsited, if not, you need to copy the lib in to each forder.

Build Project
-----
You ust use [visualstudio] to build the project.
And the Visual Studio must be higher than 15.7(VS2017)
The program will be outputed in these files:
> x86_Debug:    ./Debug/ZScratch.exe
> x86_Release:  ./Release/ZScratch.exe
> x64_Debug:    ./x64/Debug/ZScratch.exe
> x64_Release:  ./x64/Release/ZScratch.exe
