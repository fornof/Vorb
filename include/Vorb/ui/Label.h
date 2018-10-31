//
// Label.h
// Vorb Engine
//
// Created by Benjamin Arnold on 15 May 2015
// Copyright 2014 Regrowth Studios
// MIT License
//

/*! \file Label.h
* \brief 
* A simple text label widget.
*
*/

#pragma once

#ifndef Vorb_Label_h__
//! @cond DOXY_SHOW_HEADER_GUARDS
#define Vorb_Label_h__
//! @endcond

#ifndef VORB_USING_PCH
#include "Vorb/types.h"
#endif // !VORB_USING_PCH

#include "Vorb/ui/Drawables.h"
#include "Vorb/ui/Widget.h"

namespace vorb {
    namespace ui {

        /// Forward Declarations
        class UIRenderer;

        class Label : public Widget {
        public:
            /*! \brief Default constructor. */
            Label();
            /*! \brief Constructor that sets name, position, and dimensions.
            *
            * \param name: Name of the control.
            * \param dimensions: Rectangle defining the position and dimensions as the tuple <x,y,w,h>.
            */
            Label(const nString& name, const f32v4& dimensions = f32v4(0.0f));
            /*! \brief Constructor that sets name, position, and dimensions.
             *
             * \param name: Name of the control.
             * \param position: The position of the widget.
             * \param size: The size of the widget.
             */
            Label(const nString& name, const Length2& position, const Length2& size);
            /*! \brief Constructor that sets parent control, name, position, and dimensions.
            *
            * The control will be made a child of parent.
            *
            * \param parent: Parent control object.
            * \param name: Name of the control.
            * \param dimensions: Rectangle defining the position and dimensions as the tuple <x,y,w,h>.
            */
            Label(IWidget* parent, const nString& name, const f32v4& dimensions = f32v4(0.0f));
            /*! \brief Constructor that sets parent control, name, position, and dimensions.
             *
             * The widget will be made a child of parent.
             *
             * \param parent: Parent widget.
             * \param name: Name of the control.
             * \param position: The position of the widget.
             * \param size: The size of the widget.
             */
            Label(IWidget* parent, const nString& name, const Length2& position, const Length2& size);
            /*! \brief Default destructor. */
            virtual ~Label();

            /*! \brief Adds all drawables to the UIRenderer. */
            virtual void addDrawables() override;
            /*! \brief Refresh drawables. */
            virtual void refreshDrawables() override;

            /************************************************************************/
            /* Getters                                                              */
            /************************************************************************/
            virtual const vg::SpriteFont* getFont()      const { return m_drawableText.getFont();      }
            virtual         const color4& getTextColor() const { return m_drawableText.getColor();     }
            virtual        const nString& getText()      const { return m_drawableText.getText();      }
            virtual  const vg::TextAlign& getTextAlign() const { return m_drawableText.getTextAlign(); }
            virtual          const f32v2& getTextScale() const { return m_drawableText.getTextScale(); }

            /************************************************************************/
            /* Setters                                                              */
            /************************************************************************/
            virtual void setFont(const vg::SpriteFont* font);
            virtual void setText(const nString& text);
            virtual void setTextColor(const color4& color);
            virtual void setTextAlign(vg::TextAlign textAlign);
            virtual void setTextScale(const f32v2& textScale);

        protected:
            virtual void calculateDrawables() override;

            virtual void updateTextPosition();

            /************************************************************************/
            /* Members                                                              */
            /************************************************************************/
            DrawableText          m_drawableText, m_drawnText;
            const vg::SpriteFont* m_defaultFont = nullptr;
        };
    }
}
namespace vui = vorb::ui;

#endif // !Vorb_Label_h__
