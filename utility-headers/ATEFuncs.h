/*
 *  ATEFuncs.h
 *  PrintToPDF
 *
 *  Created by Comp Mac 8a on 11/17/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef ATEFUNCS_H
#define ATEFUNCS_H

#include "string.h"
#include "AIATEPaint.h"
#include "AIFont.h"
#include <functional>


extern AITextFrameSuite* sAITextFrame;
extern AIArtSuite* sAIArt;
extern AIATEPaintSuite* sAIATEPaint;
extern AIFontSuite* sAIFont;

//CONSTANT DEFINITIONS
#define WHITESPACES " \t\f\v\n\r"


ai::UnicodeString GetNameFromATETextRange(ATE::ITextRange targetRange);

std::string GetStdStringFromAITextFrame(AIArtHandle textFrame);
//This function assumes the art handle passed is a valid textFrame, will return NULL if it is not

ASReal GetFontSizeFromAITextFrame(AIArtHandle textFrame);
//This function assumes the art handle passed is a valid textFrame, will return 0 if it is not
//Returns the first font size encountered in the text frame

//Adds the text to the range with the features, the last argument defaults to After, set to 0 to insert the text before
void AddTextToRangeWithFeatures(const string text, const ATE::ICharFeatures charFeatures, ATE::ITextRange* targetRange, int BeforeAfter=1);

//Takes the passed TextFrame art object and passes each text run to the passed callback function
bool ProcessTextFrameArt(AIArtHandle textFrame, std::function<bool(ATE::ITextRange)> callback);

//Checks if a Text Range is composed entirely of whitespace characters
bool IsAllWhitespace(ATE::ITextRange theRange);

//Retrieves the color of a Text Range
// 0 = FILL,     1 = STROKE    DEFAULT = FILL
AIColor GetAIColorFromATETextRange(ATE::ITextRange theRange, bool fillOrStroke = 0);

//Sets the color of a Text Range
void SetAIColorForATETextRange(ATE::ITextRange theRange, AIColor theColor, bool fillOrStroke = 0);

//Turns a std::string into a ASUnicode array, returns the size of the array+terminator
size_t StdStringToASUnicode(const std::string text, ASUnicode* buffer, size_t bufferMax);

string GetFontNameFromFeatures(const ATE::ICharFeatures charFeatures);

#endif