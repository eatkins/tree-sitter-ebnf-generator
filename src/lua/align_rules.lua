#!/usr/bin/env lua

local file = arg[1]
assert(file, "no file specified")
local overwrite = false
for _, a in ipairs(arg) do overwrite = overwrite or a == "-f" or a == "--force" end
local verbose = not overwrite
for _, a in ipairs(arg) do if a == "-v" or a == "--verbose" then verbose = true end end
local unpack = unpack or table.unpack

local raw_lines = {}
local lines = {}
local in_rules = nil

local function reformat_lines()
  local max_len = 0
  for _, v in ipairs(raw_lines) do
    local key, delim, value = unpack(v)
    if delim then max_len = math.max(max_len, #key) end
  end
  local pipe_indent = {}
  for i = 1, max_len + (in_rules and 5 or 3) do table.insert(pipe_indent, " ") end
  pipe_indent = table.concat(pipe_indent)
  for _, v in ipairs(raw_lines) do
    local key, delim, value = unpack(v)
    if key and delim and value then
      local aligned_line = { (in_rules and "  " or "") .. key }
      for i = 1, max_len - #key do table.insert(aligned_line, " ") end
      local padded_delim = #delim == 3 and delim or (delim .. " ")
      table.insert(lines, table.concat(aligned_line) .. " " .. padded_delim .. " " .. value)
    elseif key and delim then
      local pipe_start = delim:find("%|")
      if pipe_start == 1 then
        local start, end_index = delim:find("[%s]+")
        if start == 2 and end_index > start then
          delim = "| " .. delim:sub(end_index + 1)
        end
      else
          delim = "    " .. delim
      end
      table.insert(lines, pipe_indent .. delim)
    else
      table.insert(lines, key)
    end
  end
end
for line in io.lines(file) do
  if line == "rules:" then
    reformat_lines()
    raw_lines = {}
    in_rules = true
    table.insert(lines, line)
  elseif line:find("%s*;") == 1 then
    table.insert(raw_lines, { line })
  else
    local start_pattern = (in_rules and "  " or "") .. "([^%s]+)%s*(:?:=)%s*(.*)"
    local key, delim, value = line:match(start_pattern)
    if key and delim and value then
      table.insert(raw_lines, { key, delim, value })
    else
      local pipe_pattern = "%s+([^%s;].*)"
      local s, _, tail = line:find(pipe_pattern)
      if tail and s == 1 then
        table.insert(raw_lines, { "", tail })
      else
        table.insert(raw_lines, { line })
      end
    end
  end
end
reformat_lines()
local result = table.concat(lines, "\n")
if overwrite then io.open(file, "w"):write(result) end
if verbose then print(result) end
