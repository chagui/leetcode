cc_test(
    name = "algorithm",
    srcs = glob(["algorithm/*.cpp"]),
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "@gtest//:gtest_main",
        "//src:algorithm",
    ],
    args = ["--gtest_shuffle"],
)
