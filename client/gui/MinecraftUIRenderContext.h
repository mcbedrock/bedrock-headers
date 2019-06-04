#pragma once

#include "ScreenContext.h"
#include "RectangleArea.h"
#include "TextMeasureData.h"
#include "CaretMeasureData.h"

struct MinecraftUIRenderContext : ScreenContext {
	void drawText(Font&, RectangleArea const&, std::string const&, Color const&, float, /*ui::TextAlignment*/ char, TextMeasureData const&, CaretMeasureData const&);
};