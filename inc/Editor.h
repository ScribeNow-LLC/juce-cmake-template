#ifndef EDITOR_H
#define EDITOR_H

#include <juce_audio_basics/juce_audio_basics.h>
#include "Processor.h"

/**
 * @brief Editor class for the JUCE plugin.
 */
class Editor final : public juce::AudioProcessorEditor, juce::Timer {
public:
    /**
     * @brief Constructor for the Editor.
     */
    explicit Editor(Processor &);

    /**
     * @brief Destructor for the Editor.
     */
    ~Editor() override = default;

    /**
     * @brief Paint the editor's background.
     */
    void paint(juce::Graphics &) override;

    /**
     * @brief Resize the editor.
     */
    void resized() override;

private:
    /** Reference to the JucePlugin processor */
    Processor &processor;

    /** Tooltip window for displaying information */
    juce::TooltipWindow tooltipWindow;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Editor)

    /**
     * @brief Timer callback function to update the editor.
     */
    void timerCallback() override;
};

#endif // EDITOR_H
