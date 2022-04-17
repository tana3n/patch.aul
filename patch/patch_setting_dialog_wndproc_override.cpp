/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "patch_setting_dialog_wndproc_override.hpp"

namespace patch {
	LRESULT CALLBACK setting_dialog_t::wndproc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) {
		switch (message) {
		case WM_MOVE:
			#ifdef PATCH_SWITCH_SETTINGDIALOG_MOVE
				setting_dialog_move(hwnd);
			#endif
			break;
		case WM_SIZE:
			#ifdef PATCH_SWITCH_FAST_SETTINGDIALOG
				InvalidateRect(hwnd, nullptr, FALSE);
				UpdateWindow(hwnd);
			#endif
			break;
		}
		return wndproc_orig(hwnd, message, wparam, lparam);
	}
}