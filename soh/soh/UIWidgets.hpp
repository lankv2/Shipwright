#ifndef UIWidgets_hpp
#define UIWidgets_hpp

#include <string>
#include <sstream>
#include <vector>
#include <span>
#include <stdint.h>
#ifndef IMGUI_DEFINE_MATH_OPERATORS
#define IMGUI_DEFINE_MATH_OPERATORS
#endif
#include <imgui.h>
#include "soh/ShipInit.hpp"

namespace UIWidgets {

    struct TextFilters {
        static int FilterNumbers(ImGuiInputTextCallbackData* data) {
            if (data->EventChar < 256 && strchr("1234567890", (char)data->EventChar)) {
                return 0;
            }
            return 1;
        }

        static int FilterAlphaNum(ImGuiInputTextCallbackData* data) {
            const char* alphanum = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWYZ0123456789";
            if (data->EventChar < 256 && strchr(alphanum, (char)data->EventChar)) {
                return 0;
            }
            return 1;
        }
        
    };

    // MARK: - Enums

    enum class CheckboxGraphics {
        Cross,
        Checkmark,
        None
    };
    constexpr float maxSliderWidth = 260.0f;
#ifdef __SWITCH__
    constexpr float sliderButtonWidth = 42.0f;
#elif defined(__WIIU__)
    constexpr float sliderButtonWidth = 60.0f;
#else
    constexpr float sliderButtonWidth = 30.0f;
#endif

    std::string WrappedText(const char* text, unsigned int charactersPerLine = 60);
    std::string WrappedText(const std::string& text, unsigned int charactersPerLine);

    void SetLastItemHoverText(const std::string& text);
    void SetLastItemHoverText(const char* text);

    void InsertHelpHoverText(const std::string& text);
    void InsertHelpHoverText(const char* text);

    void Tooltip(const char* text);
    void Spacer(float height);
    void PaddedSeparator(bool padTop = true, bool padBottom = true, float extraVerticalTopPadding = 0.0f, float extraVerticalBottomPadding = 0.0f);

    void RenderCross(ImDrawList* draw_list, ImVec2 pos, ImU32 col, float sz);
    bool CustomCheckbox(const char* label, bool* v, bool disabled, CheckboxGraphics disabledGraphic, bool renderCrossWhenOff = false);
    bool CustomCheckboxTristate(const char* label, int* v, bool disabled, CheckboxGraphics disabledGraphic);

    void ReEnableComponent(const char* disabledTooltipText);
    void DisableComponent(const float alpha);

    bool EnhancementCheckbox(const char* text, const char* cvarName, bool disabled = false, const char* disabledTooltipText = "", CheckboxGraphics disabledGraphic = CheckboxGraphics::Cross, bool defaultValue = false);
    bool EnhancementCheckboxTristate(const char* text, const char* cvarName, bool disabled = false, const char* disabledTooltipText = "", CheckboxGraphics disabledGraphic = CheckboxGraphics::Cross, bool defaultValue = false);
    bool PaddedEnhancementCheckbox(const char* text, const char* cvarName, bool padTop = true, bool padBottom = true, bool disabled = false, const char* disabledTooltipText = "", CheckboxGraphics disabledGraphic = CheckboxGraphics::Cross, bool defaultValue = false);
    
    bool EnhancementCombobox(const char* cvarName, std::span<const char*, std::dynamic_extent> comboArray, uint8_t defaultIndex, bool disabled = false, const char* disabledTooltipText = "", uint8_t disabledValue = -1);
    bool LabeledRightAlignedEnhancementCombobox(const char* label, const char* cvarName, std::span<const char*, std::dynamic_extent> comboArray, uint8_t defaultIndex, bool disabled = false, const char* disabledTooltipText = "", uint8_t disabledValue = -1);
    
    void PaddedText(const char* text, bool padTop = true, bool padBottom = true);
    
    bool EnhancementSliderInt(const char* text, const char* id, const char* cvarName, int min, int max, const char* format, int defaultValue = 0, bool PlusMinusButton = true, bool disabled = false, const char* disabledTooltipText = "");
    bool PaddedEnhancementSliderInt(const char* text, const char* id, const char* cvarName, int min, int max, const char* format, int defaultValue = 0, bool PlusMinusButton = true, bool padTop = true, bool padBottom = true, bool disabled = false, const char* disabledTooltipText = "");
    bool EnhancementSliderFloat(const char* text, const char* id, const char* cvarName, float min, float max, const char* format, float defaultValue, bool isPercentage, bool PlusMinusButton = true, bool disabled = false, const char* disabledTooltipText = "");
    bool PaddedEnhancementSliderFloat(const char* text, const char* id, const char* cvarName, float min, float max, const char* format, float defaultValue, bool isPercentage, bool PlusMinusButton = true, bool padTop = true, bool padBottom = true, bool disabled = false, const char* disabledTooltipText = "");
    
    bool EnhancementRadioButton(const char* text, const char* cvarName, int id);

    bool DrawResetColorButton(const char* cvarName, ImVec4* colors, ImVec4 defaultcolors, bool has_alpha);
    bool DrawRandomizeColorButton(const char* cvarName, ImVec4* colors);
    void DrawLockColorCheckbox(const char* cvarName);
    void RainbowColor(const char* cvarName, ImVec4* colors);

    void LoadPickersColors(ImVec4& ColorArray, const char* cvarname, const ImVec4& default_colors, bool has_alpha);
    bool EnhancementColor(const char* text, const char* cvarName, ImVec4 ColorRGBA, ImVec4 default_colors, bool allow_rainbow = true, bool has_alpha = false, bool TitleSameLine = false);

    void DrawFlagArray32(const std::string& name, uint32_t& flags);
    void DrawFlagArray16(const std::string& name, uint16_t& flags);
    void DrawFlagArray8(const std::string& name, uint8_t& flags);
    bool StateButton(const char* str_id, const char* label);
    bool InputString(const char* label, std::string* value);
}

#endif /* UIWidgets_hpp */
