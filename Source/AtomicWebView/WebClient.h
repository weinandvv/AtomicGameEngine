
#include <Atomic/Core/Object.h>
#include "WebRenderHandler.h"

#pragma once

class CefClient;

namespace Atomic
{

class WebClientPrivate;

class ATOMIC_API WebClient : public Object
{
    friend class WebBrowserHost;
    friend class WebClientPrivate;

    OBJECT(WebClient)

public:
    /// Construct.
    WebClient(Context* context);

    /// Destruct.
    virtual ~WebClient();

    /// call once initialized with handlers
    bool CreateBrowser(const String& initialURL, int width, int height);

    void SetSize(int width, int height);

    void SetWebRenderHandler(WebRenderHandler* handler);

    CefClient* GetCefClient();

    void SendMouseClickEvent(int x, int y, unsigned button, bool mouseUp, unsigned modifier) const;
    void SendMouseMoveEvent(int x, int y, unsigned modifier, bool mouseLeave = false) const;
    void SendMouseWheelEvent(int x, int y, unsigned modifier, int deltaX, int deltaY) const;

    void SendTextEvent(const String& text, unsigned modifiers);

    void SendKeyEvent(int scanCode, int qual, bool keyUp);

    void ShortcutCut();
    void ShortcutCopy();
    void ShortcutPaste();
    void ShortcutSelectAll();
    void ShortcutUndo();
    void ShortcutRedo();
    void ShortcutDelete();

private:

    void WasResized();

    SharedPtr<WebRenderHandler> renderHandler_;

    WebClientPrivate* d_;

};

}