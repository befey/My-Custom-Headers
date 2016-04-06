/*
 *  VPB.h
 *  PrintToPDF
 *
 *  Created by Comp Mac 8a on 2/19/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef VPB_H
#define VPB_H

#include "SDKErrors.h"
#include "AIPDFFormatAction.h"
#include "AIDocumentAction.h"
#include "AIArtboard.h"
#import <Cocoa/Cocoa.h>

extern "C"  AIActionManagerSuite* sAIActionManager;
extern "C"  AIArtboardSuite* sAIArtboard;

#define PATH_TO_PLANT_MANUFACTURING	ai::UnicodeString("/Volumes/Plant_Manufacturing")
#define DEFAULT_OUTPUTPATH "/Users/t431962/Desktop/WORKING"

class Instance
	{
	public:
		/** Value parameter block (VPB) - a container for action parameters.
		 @see AIActionManagerSuite
		 */
		class VPB
		{
		public:
			/**	Constructor
			 */
			VPB();
			
			/**	Destructor
			 */
			~VPB();
			
			/**	Returns the value parameter block structure.
			 */
			inline operator AIActionParamValueRef(void) const {return fActionParamValueRef;}
			
			
			// kAISaveDocumentAsAction parameters
			
			/**	Sets the name key of the document to save as - kAISaveDocumentAsNameKey, 
			 in the value parameter block.
			 @param name IN name to save document as.
			 */
			void SetSaveDocumentAsName(const ai::FilePath& name);
			
			/**	Sets the format key of the document to save as - kAISaveDocumentAsFormatKey, 
			 in the value parameter block.
			 @param format IN format to save document as.
			 */
			void SetSaveDocumentAsFormat(const char* format);  
			
			/**	Sets the get params key of the document to save as - kAISaveDocumentAsGetParamsKey, 
			 in the value parameter block.
			 @param getParams IN true to get params, false if not.
			 */
			void SetSaveDocumentAsGetParams(ASBoolean getParams);
			
			
			
			
		//private:
			/** The value parameter block.
			 */
			AIActionParamValueRef fActionParamValueRef;
		}; // end class VPB
		
	public:
		
		/** Gathers action parameters and saves document as PDF.
		 @param name IN name to save the document as.
		 @return kNoErr on success, other error code otherwise.
		 @see kAISaveDocumentAsAction
		 */
		ASErr SaveDocumentAsPDF(const string& name);
		
		
		/** Gathers common parameters and saves a document.
		 @param name IN name to save the document as.
		 @param vpb IN the value parameter block.
		 @return kNoErr on success, other error code otherwise.
		 @see kAISaveDocumentAsAction
		 @see SnpDocumentActionHelper::VPB
		 */
		ASErr SaveDocumentAs(const ai::UnicodeString& name, Instance::VPB& vpb);
		
		/** Saves a document as using the given parameters.
		 @param dialogStatus IN whether parameters dialog appears by default.
		 @param parameters IN the value parameter block.
		 @return kNoErr on success, other error code otherwise.
		 @see kAISaveDocumentAsAction
		 @see SnpDocumentActionHelper::VPB
		 */
		ASErr SaveDocumentAs(ActionDialogStatus dialogStatus, AIActionParamValueRef parameters);
		
	};

#endif //VPB_H