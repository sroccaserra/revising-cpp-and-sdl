---
-- Utilities

local function convert_strings_to_tile_indexes(strings, map)
  local result = {}
  for _,line in ipairs(strings) do
    local indexes = {}
    table.insert(result, indexes)
    for i = 1,#line do
      local c = line:sub(i,i)
      table.insert(indexes, map[c])
    end
  end
  return result
end

---
-- Definitions

_G.cursor_tiles = {1, 0, 2, 2}

_G.menu_bar_tiles = convert_strings_to_tile_indexes({
  'rmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmml',
  'bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb',
},{
  r = 1,
  m = 2,
  l = 3,
  b = 4,
})

local r_01 = {
  'ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss',
  'ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss',
  'sssssssssssssssssssssRssssssssssssssssssssssssssssssssssssss',
  'sssssssssRssssssssssssssssssssssssssssssssssRsssssssssssssss',
  'ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss',
  'sssssssssssssssssssCsCsCsCsCsCsCsCsCsCsCsCsCsCssssssssssssss',
  'sssssssssssssssssssCCCCCCCCCCCCCCCCCCCCCCCCCCCssssssssssssss',
  'sssssssssssssssssssCCCCCCCCCCCCCCCCCCCCCCCCCCCssssssssssssss',
  'sssssssssssssssssssCCCCCCCCCCCCCCCCCCCCCCCCCCCssssssssssssss',
  'sssssssssssssssssssCCCCCCCCCCCCCCCCCCCCCCCCCCCssssssssssssss',
  'sssssssssssssssssssCCCCCCCCCCCCCCCCCCCCCCCCCCCssssssssssssss',
  'sssssssssssssssssssCCCCCCCCCCCCCCCCCCCCCCCCCCCssssssssssssss',
  'sssssssssssssssssssCCCCCCCCCCCCCCCCCCCCCCCCCCCssssssssssssss',
  'sssssssssssssssssssCCCCCCCCCCCCCCCCCCCCCCCCCCCssssssssssssss',
  'sssssssssssssssssssCCCCCCCCCCCCCCCCCCCCCCCCCCCssssssssssssss',
  'sssssssssssssssssssCCCCCCCCCCCCCCCCCCCCCCCCCCCssssRsssssssss',
  'sssssssssssssssssssCCCCCCCCCCCCCCCCCCCCCCCCCCCssssssssssssss',
  'sssssssssssssssssssCCCCCCCCCCCCCCCCCCCCCCCCCCCssssssssssssss',
  'sssssssssssssssssssCCCCCCCCCCCCCCCCCCCCCCCCCCCssssssssssssss',
  'sssRsssssssssssssssCCCCCCCCCCCCCCCCCCCCCCCCCCCssssssssssssss',
  'sssssssssssssssssssCCCCCCCCCCCCCCCCCCCCCCCCCCCssssssssssssss',
  'sssssssssssssssssssCCCCCCCCCCCCCCCCCCCCCCCCCCCssssssssssssss',
  'sssssssssssssssssssCCCCCCCCCCCCCCCCCCCCCCCCCCCssssssssssRsss',
  'sssssssssssssssssssCCCCCCCCCCCCCCCCCCCCCCCCCCCssssssssssssss',
  'sssssssssssssssssssCCCCCCCCCCCCCCCCCCCCCCCCCCCssssssssssssss',
  'sssssssssssssssssssCCCCCCCCCCCCCCCCCCCCCCCCCCCssssssssssssss',
  'sssssssssssssssssssCCCCCCCCCCCCCCCCCCCCCCCCCCCssssssssssssss',
  'sssssssssssssssssssCCCCCCCCCCCCCCCCCCCCCCCCCCCssssssssssssss',
  'sssssssssssssssssssCCCCCCCCCCCCCCCCCCCCCCCCCCCssssssssssssss',
  'ggggggggggttttttttgggggggggggggggggggggggggggggggggggggggggg',
  'eeeeeeeeeewwwwwbwweeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee',
  'eeeeeeeeeewwwwwwwweeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee',
}

local r_01_map = {
  C = 32, -- plain bricks
  s = 64, -- plain sky
  R = 65, -- sky with star
  g = 96, -- ground
  e = 97, -- earth
  t = 98, -- water top
  w = 99, -- water
  b = 100, -- bubble
}

_G.room_01 = convert_strings_to_tile_indexes(r_01, r_01_map)
