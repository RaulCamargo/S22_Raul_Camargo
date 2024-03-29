#pragma once

#include "WindowImplementation.h"
#include "FlapjackUtil.h"
#include "Events.h"

namespace FJ
{
	class FLAPJACK_API GameWindow
	{
	public:
		static void Init();
		static GameWindow* GetWindow();

		bool CreateWindow(int width, int height, const std::string& windowName);
		void SwapBuffers();
		void CollectEvents();
		int GetWidth() const;
		int GetHeight() const;

		void SetKeyPressedCallback(const std::function<void(const KeyPressedEvent&)>& keyPressedCallback);
		void SetKeyReleasedCallback(const std::function<void(const KeyReleasedEvent&)>& keyReleasedCallback);

	private:
		inline static GameWindow* mInstance{ nullptr };

		GameWindow();

		WindowImplementation* mWindow{ nullptr };
	};

}

// GameWindow::GetWindow()->GetWidth(); Can run from anywhere in engine. Use GetHeight() for height.