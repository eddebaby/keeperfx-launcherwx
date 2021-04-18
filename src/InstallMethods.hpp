/******************************************************************************/
// Utility routines.
/******************************************************************************/
/** @file InstallMethods.hpp
 *     Header file for InstallMethods.cpp.
 * @par Purpose:
 *     A frame which allows chosing the installation method 
 *     (Choose folder, or search automatically for data).
 * @par Comment:
 *     None.
 * @author   Ed Kearney
 * @date     18 Apr 2021 - 18 Apr 2021
 * @par  Copying and copyrights:
 *     This program is free software; you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation; either version 2 of the License, or
 *     (at your option) any later version.
 */
/******************************************************************************/
#ifndef INSTALLMETHODS_HPP_
#define INSTALLMETHODS_HPP_
#include <wx/wx.h>

class InstallMethods : public wxDialog
{
    enum {
        eventID_InstallChoice = wxID_HIGHEST+20,
        eventID_InstallAuto,
        eventID_InstallCancel,
    };
    wxBoxSizer * topsizer;

public:
    InstallMethods(wxFrame *parent);
    virtual ~InstallMethods();

    // event handlers
    void OnClose(wxCloseEvent& event);
    void OnCancel(wxCommandEvent& event);

private:
    void onInstallChoice(wxCommandEvent& event);
    void onInstallAuto(wxCommandEvent& event);

    // any class wishing to process wxWidgets events must use this macro
    DECLARE_EVENT_TABLE()
};

/******************************************************************************/
#endif /* INSTALLMETHODS_HPP_ */
