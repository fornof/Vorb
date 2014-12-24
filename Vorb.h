// 
//  Vorb.h
//  Vorb Engine
//
//  Created by Ben Arnold on 2/10/2014
//  Copyright 2014 Regrowth Studios
//  All Rights Reserved
//  
//  This is the main header for the vorb engine. It 
//  contains the namespace declarations.

#pragma once

#ifndef VORB_H_
#define VORB_H_

// Create empty namespaces for aliasing purposes
namespace vorb{
    namespace core{
        namespace graphics { }
    }
    namespace voxel { }
    namespace ui { }
    namespace io { }
}

// Namespace aliases
namespace vcore = vorb::core; ///< Namespace alias vorb::core
namespace vg = vorb::core::graphics; ///< Namespace alias vorb::core::graphics
namespace vvox = vorb::voxel; ///< Namespace alias vorb::voxel
namespace vui = vorb::ui; ///< Namespace alias vorb::ui
namespace vio = vorb::io; ///< Namespace alias vorb::ui

// Pre-declaration helpers
#define DECL_VORB(CONTAINER, TYPE) namespace vorb { CONTAINER TYPE; }
#define DECL_VCORE(CONTAINER, TYPE) namespace vorb { namespace core { CONTAINER TYPE; }  }
#define DECL_VG(CONTAINER, TYPE) namespace vorb { namespace core { namespace graphics { CONTAINER TYPE; } }  }
#define DECL_VVOX(CONTAINER, TYPE) namespace vorb { namespace voxel { CONTAINER TYPE; }  }
#define DECL_VUI(CONTAINER, TYPE) namespace vorb { namespace ui { CONTAINER TYPE; }  }
#define DECL_VIO(CONTAINER, TYPE) namespace vorb { namespace io { CONTAINER TYPE; }  }

namespace vorb {
    enum class InitParam {
        NONE = 0x00,
        GRAPHICS = 0x01,
        IO = 0x02,
        SOUND = 0x04,
        ALL = GRAPHICS | SOUND | IO
    };
    ENUM_CLASS_OPS_INL(vorb::InitParam, ui64)

    InitParam init(const InitParam& p);
}

#endif // VORB_H_