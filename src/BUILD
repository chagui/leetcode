cc_library(
    name = "helpers",
    srcs = glob(["helpers/*.cpp"]),
    hdrs = glob(["helpers/*.h"]),
    visibility = ["//test:__pkg__"],
)

cc_library(
    name = "algorithm",
    srcs = glob(["algorithm/*.cpp"]),
    hdrs = glob(["algorithm/*.h"]),
    copts = ["-Iexternal/gtest/include"],
    visibility = ["//test:__pkg__"],
    deps = [
        "//src:helpers",
        "@gtest//:gtest",
    ],
)

cc_library(
    name = "concurrency",
    srcs = glob(["concurrency/*.cpp"]),
    hdrs = glob(["concurrency/*.h"]),
    visibility = ["//test:__pkg__"],
)
