import qbs

CppApplication {
    consoleApplication: true
    files: [
        "cpu.cpp",
        "cpu.h",
        "main.cpp",
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
