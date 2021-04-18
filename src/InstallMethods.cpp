/******************************************************************************/
// Utility routines.
/******************************************************************************/
/** @file InstallMethods.cpp
 *     A frame which allows chosing the installation method 
 *     (Choose folder, or search automatically for data).
 * @par Purpose:
 *     Allow the user to either choose the folder that contains a valid Dungeon 
 *     Keeper install/disc, or search their computer automatically instead.
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
#include "InstallMethods.hpp"
#include "LauncherApp.hpp"

BEGIN_EVENT_TABLE(InstallMethods, wxDialog)
    EVT_CLOSE(InstallMethods::OnClose)
    EVT_BUTTON(eventID_InstallChoice, InstallMethods::onInstallChoice)
    EVT_BUTTON(eventID_InstallAuto, InstallMethods::onInstallAuto)
    EVT_BUTTON(eventID_InstallCancel, InstallMethods::OnCancel)
END_EVENT_TABLE()

InstallMethods::InstallMethods(wxFrame *parent)
    : wxDialog (parent, -1, wxT("Install KeeperFX"), wxDefaultPosition, wxSize(480, 480), (wxRESIZE_BORDER | wxCAPTION | wxBORDER_NONE))
{
    topsizer = new wxBoxSizer( wxVERTICAL );

    wxPanel *dlgMainPanel = new wxPanel(this, wxID_ANY);
    wxBoxSizer *dlgMainPanelSizer = new wxBoxSizer( wxHORIZONTAL );
    {
        //dlgMainPanelSizer->AddStretchSpacer(1);
        //wxStaticText *installTxt = new wxStaticText(dlgMainPanel, wxID_ANY, wxT("Click the Choose Folder button if you know where Dungeon Keeper is located"));
        //installTxt->SetToolTip(tooltips_eng[8]);
        //dlgMainPanelSizer->Add(installTxt, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL);
        //dlgMainPanelSizer->AddSpacer(16);
        dlgMainPanelSizer->AddStretchSpacer(1);
        wxButton *chooseBtn = new wxButton(dlgMainPanel, eventID_InstallChoice, _T("Choose &Folder") );
        //chooseBtn->SetToolTip(tooltips_eng[10]);
        dlgMainPanelSizer->Add(chooseBtn, 0, wxEXPAND);
        dlgMainPanelSizer->AddStretchSpacer(1);
        wxButton *autoBtn = new wxButton(dlgMainPanel, eventID_InstallAuto, _T("&Auto Find Files") );
        //autoBtn->SetToolTip(tooltips_eng[11]);
        dlgMainPanelSizer->Add(autoBtn, 0, wxEXPAND);
        dlgMainPanelSizer->AddStretchSpacer(1);
        wxButton *cancelBtn = new wxButton(dlgMainPanel, eventID_InstallCancel, _T("&Cancel") );
        //cancelBtn->SetToolTip(tooltips_eng[11]);
        dlgMainPanelSizer->Add(cancelBtn, 0, wxEXPAND);
        dlgMainPanelSizer->AddStretchSpacer(1);
    }
    dlgMainPanel->SetSizer(dlgMainPanelSizer);
    topsizer->Add(dlgMainPanel, 0, wxEXPAND);

    SetSizer(topsizer);
    Fit();
    Centre(wxBOTH);
}

InstallMethods::~InstallMethods(void)
{
}

void InstallMethods::OnCancel(wxCommandEvent& WXUNUSED(event))
{
    // End without generating OnClose event
    EndModal(0);
}

void InstallMethods::OnClose(wxCloseEvent& event)
{
    EndModal(1);
}

void InstallMethods::onInstallAuto(wxCommandEvent& WXUNUSED(event))
{
    LauncherFrame *parent = wxDynamicCast(this->GetParent(), LauncherFrame);
    if(parent)
        parent->onInstallAutoFindFiles();
    Close();
}

void InstallMethods::onInstallChoice(wxCommandEvent& WXUNUSED(event))
{
    LauncherFrame *parent = wxDynamicCast(this->GetParent(), LauncherFrame);
    if(parent)
    {
        parent->onInstallChooseFolder();
    }
    Close();
}
/******************************************************************************/
