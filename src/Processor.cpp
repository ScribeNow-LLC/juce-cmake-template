#include "Processor.h"
#include "Editor.h"

/**
 * @brief Constructor for the Processor.
 */
Processor::Processor() :
    AudioProcessor(
            BusesProperties()
                    .withInput("Input", juce::AudioChannelSet::stereo(), true)
                    .withOutput("Output", juce::AudioChannelSet::stereo(),
                                true)),
    parameters(*this, nullptr, "PARAMETERS", createParameterLayout()) {}

/**
 * @brief Prepare the processor for playback.
 * @param sampleRate The sample rate of the audio stream.
 * @param samplesPerBlock The number of samples per block to process.
 */
void Processor::prepareToPlay(double sampleRate, int samplesPerBlock) {
    /// Setup things here
}

/**
 * @brief Release any resources used by the processor.
 */
void Processor::releaseResources() {
    /// Release things here
}

/**
 * @brief Check if the processor supports the given bus layout.
 * @param layouts The bus layout to check for support.
 * @return True if the layout is supported, false otherwise.
 */
auto Processor::isBusesLayoutSupported(const BusesLayout &layouts) const -> bool {
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono() &&
        layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    return true;
}

/**
 * @brief Process a block of audio and MIDI data.
 */
void Processor::processBlock(juce::AudioBuffer<float> &buffer,
                             juce::MidiBuffer &midiMessages) {
    /// Clear output buffer for now
    buffer.clear();
}

/**
 * @brief Create an editor for the processor.
 * @return A pointer to the created editor.
 */
auto Processor::createEditor() -> juce::AudioProcessorEditor* {
    return new Editor(*this);
}

/**
 * @brief Create the parameter layout for the processor.
 * @return The parameter layout for the processor.
 */
auto Processor::createParameterLayout() -> juce::AudioProcessorValueTreeState::ParameterLayout {
    juce::AudioProcessorValueTreeState::ParameterLayout layout;
    /// Add parameters
    layout.add(std::make_unique<juce::AudioParameterBool>("bypass", "Bypass",
                                                          false));
    return layout;
}

/**
 * @brief Factory function to create an instance of the PDrum
 * processor.
 * @return A pointer to the created processor instance.
 */
auto JUCE_CALLTYPE createPluginFilter() -> juce::AudioProcessor * {
    return new Processor();
}
