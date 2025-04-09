#include "Editor.h"

/**
 * @brief Constructor for the NBandParametricEQEditor class.
 * @param p A reference to the NBandParametricEQ processor that this editor
 * is associated with.
 */
Editor::Editor(Processor &p) : AudioProcessorEditor(p), processor(p) {
    setSize(300, 400);
    setResizable(true, true);
    setResizeLimits(300, 400, 1000, 600);
    startTimerHz(60);
}

/**
 * @brief Paint the editor's background.
 * @param g The graphics context used for painting.
 */
void Editor::paint(juce::Graphics &g) {
    g.fillAll(getLookAndFeel().findColour(
            juce::ResizableWindow::backgroundColourId));
}

/**
 * @brief Resize the editor.
 */
void Editor::resized() {
    // juce::Rectangle<int> area = getLocalBounds();
}

/**
 * @brief Timer callback function to update the editor.
 */
void Editor::timerCallback() { repaint(); }
