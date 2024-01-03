#ifndef  GUI_H
#define  GUI_H
#include "DearGUI/imgui.h"
#include "DearGUI/imgui_sdl.h"
#include "../FileSystem/DirectoryHandler.h"
#include <SDL_events.h>

/// <summary>
/// Very important note here since your are abstracting your renderers between three systems 
/// make sure that properly handle the render function call process to handle their apporiate library class 
/// here for example, you need to create a seperate OpenGL Render process because how you intialize ImGui is different with OpenGL
/// 2021-10-17
/// </summary>
class DogEngine;
struct ConsoleApp
{
	char InputBuf[256];
	ImVector<char*> Items;
	ImVector<const char*> commands;
	ImVector<char*> History;
	int HistoryPos;
	ImGuiTextFilter Filter;
	bool autoScoller;
	bool scrollToBottom;

	ConsoleApp()
	{
		// "CLASSIFY" is here to provide the test where "C"+[tab] completes to "CL" and display multiple matches.
		commands.push_back("HELP");
		commands.push_back("HISTORY");
		commands.push_back("CLEAR");
		commands.push_back("CLASSIFY");
		autoScoller = true;
		scrollToBottom = false;
		AddLog("Example Console");
	}
	~ConsoleApp()
	{
		ClearLog();
		for (int i = 0; i < History.Size; i++)
		{
			free(History[i]);
		}
	}

	// Portable helpers
	static int   Stricmp(const char* s1, const char* s2) { int d; while ((d = toupper(*s2) - toupper(*s1)) == 0 && *s1) { s1++; s2++; } return d; }
	static int   Strnicmp(const char* s1, const char* s2, int n) { int d = 0; while (n > 0 && (d = toupper(*s2) - toupper(*s1)) == 0 && *s1) { s1++; s2++; n--; } return d; }
	static char* Strdup(const char* s) { size_t len = strlen(s) + 1; void* buf = malloc(len); IM_ASSERT(buf); return (char*)memcpy(buf, (const void*)s, len); }
	static void  Strtrim(char* s) { char* str_end = s + strlen(s); while (str_end > s && str_end[-1] == ' ') str_end--; *str_end = 0; }
	void ClearLog()
	{
		for (int i = 0; i < Items.Size; i++)
		{
			free(Items[i]);
			Items.clear();
		}
	}

	void AddLog(const char* fmt, ...) IM_FMTARGS(2)
	{
		// FIXME-OPT
		char buf[1024];
		va_list args;
		va_start(args, fmt);
		vsnprintf(buf, IM_ARRAYSIZE(buf), fmt, args);
		buf[IM_ARRAYSIZE(buf) - 1] = 0;
		va_end(args);
		Items.push_back(Strdup(buf));
	}

	void Draw(const char* title, bool* p_open)
	{
		ImGui::SetNextWindowSize(ImVec2(520, 600), ImGuiCond_FirstUseEver);
		if (!ImGui::Begin(title,p_open))
		{
			ImGui::End();
			return;
		}

		if (ImGui::BeginPopupContextItem())
		{
			if (ImGui::MenuItem("Close Console"))
			{
				*p_open = false;
				ImGui::EndPopup();
			}
		}
		// Reserve enough left-over height for 1 separator + 1 input text
		const float footer_height_to_reserve = ImGui::GetStyle().ItemSpacing.y + ImGui::GetFrameHeightWithSpacing();
		ImGui::BeginChild("ScrollingRegion", ImVec2(0, -footer_height_to_reserve), false, ImGuiWindowFlags_HorizontalScrollbar);
		if (ImGui::BeginPopupContextWindow())
		{
			if (ImGui::Selectable("Clear")) ClearLog();
			ImGui::EndPopup();
		}

	
		for (int i = 0; i < Items.Size; i++)
		{
			const char* item = Items[i];
			if (!Filter.PassFilter(item))
				continue;
			

			// Normally you would store more information in your item than just a string.
			// (e.g. make Items[] an array of structure, store colour/type etc.) 
			ImVec4 colour;
			bool has_colour = false;
			if (strstr(item, "[error]")) { colour = ImVec4(1.0f, 0.4f, 0.4f, 1.0f); has_colour = true; }
			else if (strncmp(item, "# ", 2) == 0) { colour = ImVec4(1.0f, 0.8f, 0.6f, 1.0f); has_colour = true; }
			if (has_colour)
				ImGui::PushStyleColor(ImGuiCol_Text, colour);
			ImGui::TextUnformatted(item);
			if (has_colour)
				ImGui::PopStyleColor();
		}
		
		ImGui::LogFinish();

		if (scrollToBottom || (autoScoller && ImGui::GetScrollY() >= ImGui::GetScrollMaxY()))
			ImGui::SetScrollHereY(1.0f);
		scrollToBottom = false;

		ImGui::EndChild();
		ImGui::Separator();

		// Command-line 
		bool reclaim_focus = false;
		ImGuiInputTextFlags input_text_flags = ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_CallbackCompletion | ImGuiInputTextFlags_CallbackHistory;
		if (ImGui::InputText("Input", InputBuf, IM_ARRAYSIZE(InputBuf), input_text_flags, &TextEditCallbackStub, (void*)this))
		{
			char* s = InputBuf;
			Strtrim(s);
			if (s[0])
				ExceCommand(s);
			strcpy(s, "");
			reclaim_focus = true;
		}

		// Auto-focus on window apparition 
		ImGui::SetItemDefaultFocus();
		if (reclaim_focus)
			ImGui::SetKeyboardFocusHere(-1);

		ImGui::End();
	}
	
	void ExceCommand(const char* command_line)
	{
		AddLog("# %s\n", command_line);

		// Insert into history. First find match and delete it so it can be pushed to the back. 
		// This isn't trying to be smart or optimal.
		HistoryPos = -1;
		for (int i = History.Size - 1; i >= 0; i--)
		{
			if (Stricmp(History[i], command_line) == 0)
			{
				free(History[i]);
				History.erase(History.begin() + i);
				break;
			}
			History.push_back(Strdup(command_line));

			// Process command
			if (Stricmp(command_line, "Clear")==0)
			{
				ClearLog();
			}
			else if (Stricmp(command_line, "Help") == 0)
			{
				AddLog("Commands:");
				for (int i = 0; i < commands.Size; i++)
					AddLog("- %s", commands[i]);
			}
			else if (Stricmp(command_line, "History") ==0)
			{
				int first = History.Size - 10;
				for (int i = first > 0 ? first : 0; i < History.Size; i++)
					AddLog("%3d: %s\n", i, History[i]);
			}
			else
			{
				AddLog("Unknown command: '%s'\n", command_line);
			}

			// On command input, we scroll to bottom even if AutoScroll ==false
			scrollToBottom = true;
		}
	}

	/// know what you are doing. 
	//In C++11 you'd be better off using lambdas for this sort of forwarding callbacks
	static int TextEditCallbackStub(ImGuiTextEditCallbackData* data)
	{
		ConsoleApp* console = (ConsoleApp*)data->UserData;
		return console->TextEditCallbackStub(data);
	}
};

class GUI
{
public:
	GUI();
	~GUI();
	void OnCreate();
	void OnDestroy();
	void HandleEvents(SDL_Event* e_);
	void Update(float deltaTime_);
	void Render();
private:
	bool DisplayWindowMenuBar(); 
	void DisplayConsole();
	int mouseX, mouseY;
	int wheel;
	int buttons;
	ImGuiIO* io;
	ConsoleApp consoleapp;
};

#endif // ! GUI_H