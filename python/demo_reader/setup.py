import setuptools

setuptools.setup(
  name="demo_reader",
  version="1.0.0",
  description="Tools for reading various file fotmats",
  packages=setuptools.find_packages("src"),
  package_dir={"":"src"},
)
