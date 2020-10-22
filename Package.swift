// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "Castify",
    platforms: [ .iOS(.v10) ],
    products: [
        .library(
            name: "Castify",
            targets: ["Castify"])
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "Castify",
            path: "Castify.xcframework"
        )
    ]
)
