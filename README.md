# CMake JUCE Template

Create a new repository and use this as a template to start your JUCE project.
This project fully uses CMake and does not use the ProJucer for anything. Right
now, this is configured to create a blank plugin with no Components. 

- - -
# Requirements

- CMake 3.30 or higher
- clang-tidy
- curl (_for Linux builds only_)

- - -
# Checkout Checklist

After templating your repository with this template, you should do the 
following:
1. `CMakeLists.txt`:
    - **a.** Customize the project name `juce_cmake_plugin` on `line 5`:
        - ```
          project(juce_cmake_plugin VERSION 1.0.0)
          ``` 
        - _Example_:
          ```
          project(Graphverb VERSION 1.0.0)
          ``` 
    - **b.** Update the `COMPANY_NAME`, `PRODUCT_NAME`, and `BUNDLE_ID` on `lines 68-70`:
        - ```
          COMPANY_NAME ""
          PRODUCT_NAME ""
          BUNDLE_ID ""
          ```
        - _Example_:
          ```
          COMPANY_NAME "Scribe Now LLC"
          PRODUCT_NAME "Graphverb"
          BUNDLE_ID "com.scribenow.graphverb"
          ``` 
    - **c.** (Optional) If this plugin will be a synthesizer, make sure to enable
          that on `line 74`:
        - ```
          IS_SYNTH TRUE
          ``` 
        - **Don't** do this if you don't intend to make your plugin a synthesizer,
          as marking this as true will block any input audio.
    - **d.** Update the target name `juce_cmake_plugin` - you can use the same name
          you used when renaming the CMake project. Do this on:
        - `line 67`
        - `line 82`
        - `line 88`
        - `line 93`
        - `line 96`
        - `line 105`
        - `line 114`
            - If, for example, you chose to rename the target to `Graphverb`, 
              this line would become:
              ```
              set(target_name "Graphverb_${format}")
              ```
        - `line 124`
2. `.github/workflows/pr_check.yml`:
    - **a.** Update the `name` field on `line 1`
    - **b.** Update `PLUGIN_NAME` on `line 11` with the target name you chose in 
          Step 1.d.
3. `.github/workflows/release.yml`:
    - TODO - provide instructions for updating this to support code-signing



- - -
# Building

## Standalone:
During development, it's much easier to generate a standalone version that can 
run outside a DAW. 

**Debug:**
```
cd juce-cmake-template
cmake -DCMAKE_BUILD_TYPE=Debug --preset "JUCE Debug" -S . -B build/debug
cmake --build build/debug --target juce_cmake_plugin_Standalone -j
```

**Release:**
```
cd juce-cmake-template
cmake -DCMAKE_BUILD_TYPE=Release --preset "JUCE Release" -S . -B build/release
cmake --build build/release --target juce_cmake_plugin_Standalone -j
```

**If you changed the name of the target in Step 1.d., make sure to use that 
instead of `juce_cmake_plugin`.**
- For example, if you changed the target name to `Graphverb`, you would use 
  `Graphverb_Standalone` as the target when building.

## VST3 & AU:

To build and generate a `.vst3` and `.component` file, just replace the target
name with `juce_cmake_plugin_VST3` or `juce_cmake_plugin_AU` in the
commands above. Again, if you changed the name in Step 1.d., make sure to
replace `juce_cmake_plugin` with the name you chose.

You can also use the target name `juce_cmake_plugin_All` to build all defined 
plugin types at once.

- - - 
# Generating a Release:

When generating a release, it is __strongly__ recommended to use code-signing. 
Right now, I've only set this up for macOS builds.

TODO - Add instructions for code-signing.

To generate a release, just tag the latest commit on `main` with a version 
number that starts with `v`, like `v1.0.0`. This will trigger the 
`.github/workflows/release.yml` workflow, which will build the release and
upload it to the `releases` page.