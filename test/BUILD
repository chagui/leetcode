load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "algorithm",
    srcs = glob(["algorithm/*.cpp"]),
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "@gtest//:gtest_main",
        "//src:algorithm",
    ],
)
