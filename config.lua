local r = 1 -- top right corner
local m = 2 -- top middle
local l = 3 -- top left corner
local b = 4 -- bottom

_G.menu_bar_tiles = {
  {
    r,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,
    m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,m,l,
  },
  {
    b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,
    b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,
  },
}

local C = 32 -- plain bricks
local s = 64 -- plain sky
local R = 65 -- sky with star
local g = 96 -- ground
local e = 97 -- earth
local t = 98 -- water top
local w = 99 -- water
local b = 100 -- bubble

_G.room_01 = {
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,R,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {s,s,s,s,s,s,s,s,s,R,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,R,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,C,s,C,s,C,s,C,s,C,s,C,s,C,s,C,s,C,s,C,s,C,s,C,s,C,s,C,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,s,s,s,s,R,s,s,s,s,s,s,s,s,s},
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {s,s,s,R,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,s,s,s,s,s,s,s,s,s,s,R,s,s,s},
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,C,s,s,s,s,s,s,s,s,s,s,s,s,s,s},
  {g,g,g,g,g,g,g,g,g,g,t,t,t,t,t,t,t,t,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g,g},
  {e,e,e,e,e,e,e,e,e,e,w,w,w,w,w,b,w,w,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e},
  {e,e,e,e,e,e,e,e,e,e,w,w,w,w,w,w,w,w,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e,e},
}

_G.cursor_tiles = {1, 0, 2, 2}
