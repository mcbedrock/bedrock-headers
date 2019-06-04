#pragma once

#include "ScreenContext.h"
#include "RectangleArea.h"

class TextMeasureData {
	TextMeasureData(float, float, bool, bool, bool) {}
};

class CaretMeasureData {
	CaretMeasureData(int, bool) {}
};

struct MinecraftUIRenderContext : ScreenContext {
	void drawText(Font&, RectangleArea const&, std::string const&, Color const&, float, /*ui::TextAlignment*/ char, TextMeasureData const&, CaretMeasureData const&);
};