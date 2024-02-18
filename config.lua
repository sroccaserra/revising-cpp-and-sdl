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
  '.......................^.................^..................',
  '......................qrs.......^.......qrs.................',
  '.....................qrrrs.....qrs.....qrrrs................',
  '.........R..........qrrrrrs...qrrrs...qrrrrrs...............',
  '...................qrrrrrrrs.qrrrrrs.qrrrrrrrs..............',
  '...................B.B.B.B.B.B.B.B.B.B.B.B.B.B..............',
  '...................BBBBBBBBB.BBBBBBB.BBBBBBBBB..............',
  '...................ABBBBBBBC.ABBBBBC.ABBBBBBBC..............',
  '....................BBBBBBB...BCABB...BBBBBBB...............',
  '....................BBBBBBB...B..BB...BBBBBBB...............',
  '....................BBBBBBB...B..BB...BBBBBBB...............',
  '....................BBBBBBBBBBBBBBBBBBBBBBBBC...............',
  '....................BBBBBBBBBBBBBBBBBBBBBBBB................',
  '....................ABBBBBBBBBBBBBBBBBBBBBBB................',
  '.....................BBBBBBBBBBBBBBBBBBBBBBB................',
  '.....................BBBBBBBBBBBBBBBBBBBBBBB......R.........',
  '.....................BBBBBBBBBBBBBBBBBBBBBBC................',
  '.....................BBBCABBBCABBBCABBCABBB.................',
  '.....................BBB..BBB..BBB..BB..BBB.................',
  '...R.................BBBBBBBBBBBBBBBBBBBBBB.................',
  '.....................BBBBBBBBBBBBBBBBBBBBBB.................',
  '.....................BBBBBBBBBBBBBBBBBBBBBB.................',
  '.....................BBBBBBBBBBCABBBBBBBBBC.............R...',
  '.....................BBBBBBBBBB..BBBBBBBBB..................',
  '.....................BBBCABBBBB..BBBBBBBBB..................',
  '.....................BBB..BBBBB..BBBBBBBBB...........gg.....',
  '.....................BBB..BBBBB..BBBBCABBB.........ggee.....',
  '.....................BBB..BBBBBBBBBBB..BBB.......ggeeee.....',
  '.....................BBB..BBBBBBBBBBB..BBB.....ggeeeeee.....',
  'ggggggggggttttttttgggggggggggggggggggggggggggggeeeeeeegggggg',
  'eeeeeeeeeewwwwwwwweeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee',
  'eeeeeeeeeewwwwwwwweeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee',
}

local r_01_map = {
  A = 32, -- \ bricks
  B = 33, -- plain bricks
  C = 34, -- / brick

  q = 66, -- roof left
  r = 67, -- roof
  s = 68, -- roof right
  ['^'] = 69,

  ['.'] = 64, -- plain sky
  R = 65, -- sky with star

  g = 96, -- ground
  e = 97, -- earth

  t = 98, -- water top
  w = 99, -- water
  b = 100, -- bubble
}

_G.room_01 = convert_strings_to_tile_indexes(r_01, r_01_map)
