import setuptools

setuptools.setup(
    name="multi_reader_bz2_plugin",
    version="0.0.0",
    description="multi_reader plugin for reading bz2 files",
    packages=setuptools.find_packages("src"),
    package_dir={"": "src"},
    entry_points={
        "multi_reader.plugins": [
            "bz2 = multi_reader_bz2.bzipped",
        ],
    },
)
