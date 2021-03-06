/*************************************************************************
*    UrBackup - Client/Server backup system
*    Copyright (C) 2011  Martin Raiber
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
**************************************************************************/

#include <wx/wx.h>
#include <wx/timer.h>
#include <wx/intl.h>

wxIcon getAppIcon(wxString fn);

wxString getStatusText(wxString status);

wxString getPercentText(wxString pcdone);

class MyApp : public wxApp
{
  public:
    virtual bool OnInit();
	virtual int OnExit();

private:
	wxLocale m_locale;
};

class MyTimer : public wxTimer
{
public:
	MyTimer(void);

	void Notify(void);

	bool hasCapability(int capa_bit);
	static bool hasCapability(int capa_bit, int capa);

	int getCapa()
	{
		return capa;
	}

	void resetDisplayedUpdateInfo(void);

private:
	int capa;
	bool displayed_update_info;
};