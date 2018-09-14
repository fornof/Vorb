//
// Viewport.h
// Vorb Engine
//
// Created by Benjamin Arnold on 10 May 2015
// Copyright 2014 Regrowth Studios
// All Rights Reserved
//

/*! \file Viewport.h
* @brief 
* Represents an in-game UI window.
*
*/

#pragma once

#ifndef Vorb_Form_h__
//! @cond DOXY_SHOW_HEADER_GUARDS
#define Vorb_Form_h__
//! @endcond

#ifndef VORB_USING_PCH
#include "Vorb/types.h"
#endif // !VORB_USING_PCH

#include "Vorb/Events.hpp"
#include "Vorb/VorbPreDecl.inl"
#include "Vorb/ui/IWidget.h"
#include "Vorb/ui/UIRenderer.h"
#include "Vorb/ui/IGameScreen.h"

DECL_VG(class SpriteFont; class SpriteBatch)

namespace vorb {
    namespace ui {

        // Forward Declarations
        class GameWindow;

        class Viewport : public IWidget {
        public:
            Viewport(const GameWindow* window = nullptr);
            virtual ~Viewport();

            /*! @brief Initializes the viewport and its renderer.
             * 
             * @param name: The name of the viewport.
             * @param destRect: Position and size of the viewport.
             * @param defaultFont: The optional default font to use.
             * @param defaultFont: The optional SpriteBatch to use.
             */
            virtual void init(const nString& name, const f32v4& destRect, vg::SpriteFont* defaultFont = nullptr, vg::SpriteBatch* spriteBatch = nullptr);

            /*! @brief Adds a widget to the viewport and initializes it for rendering.
             * 
             * @param widget: The widget to add.
             * @return true on success.
             */
            virtual bool addWidget(IWidget* widget) override;
            /*! @brief Removes a widget from the viewport.
            *
            * @param widget: The widget to remove.
            * @return true on success.
            */
            virtual bool removeWidget(IWidget* widget) override;

            /*! @brief Updates the viewport and all descendant widgets.
             * 
             * @param dt: Time since the last update.
             */
            virtual void update(f32 dt = 1.0f);

            /*! @brief Draws the Form. */
            virtual void draw();
            /*! @brief Frees all resources. */
            virtual void dispose() override;

            /************************************************************************/
            /* Getters                                                              */
            /************************************************************************/
            virtual       UIRenderer* getRenderer()         { return &m_renderer; }
            virtual const GameWindow* getGameWindow() const { return m_window; }

            /************************************************************************/
            /* Getters                                                              */
            /************************************************************************/
            virtual void setGameWindow(const GameWindow* window) { m_window = window; m_flags.needsDimensionUpdate = true; }
        protected:
            /************************************************************************/
            /* Event Handlers                                                       */
            /************************************************************************/
            virtual void onResize(Sender s, const WindowResizeEvent& e);

            /************************************************************************/
            /* Members                                                              */
            /************************************************************************/
            UIRenderer m_renderer;      ///< The UI Renderer.
            const GameWindow* m_window; ///< The window to which this UI is drawn.
        };
    }
}
namespace vui = vorb::ui;

#endif // !Vorb_Form_h__
