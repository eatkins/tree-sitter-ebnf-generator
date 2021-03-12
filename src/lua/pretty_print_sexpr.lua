local lpeg = require 'lpeg' -- see http://www.inf.puc-rio.br/~roberto/lpeg/

local imports = 'P R S C V match'
for w in imports:gmatch('%a+') do _G[w] = lpeg[w] end -- make e.g. 'lpeg.P' function available as 'P'

function tosymbol(s) return s end
function tolist(x, ...) return {...} end -- ignore the first capture, the whole sexpr

local ws = S' \t\n'^0                 -- whitespace, 0 or more

local digits = R'09'^1                -- digits, 1 or more
local Tnumber = C(digits * (P'.' * digits)^-1) * ws / tonumber -- ^-1 => at most 1

local Tstring = C(P'"' * (P(1) - P'"')^0 * P'"') * ws

local sep = S'()" \t\n'
local symstart = (P(1) - (R'09' + sep))
local symchar = (P(1) - sep)
local Tsymbol = C(symstart * symchar^0) * ws / tosymbol

local atom = Tnumber + Tstring + Tsymbol
local lpar = P'(' * ws
local rpar = P')' * ws
local sexpr = P{ -- defines a recursive pattern
  'S';
  S = ws * lpar * C((atom + V'S')^0) * rpar / tolist
}


local function pprints(expr, indent)
  local function prindent(fmt, expr)
    io.write(indent) -- no line break
    print(string.format(fmt, expr))
  end
  if type(expr) == 'table' then
    if #expr == 0 then
      prindent('()')
    else
      prindent('(')
      local indentmore = '  ' .. indent
      for i= 1,#expr do pprints(expr[i], indentmore) end
      prindent(')')
    end
  elseif type(expr) == 'string' then
    if expr:sub(1,1) == '"' then
      prindent("%q", expr:sub(2,-2)) -- print as a Lua string
    else
      prindent("%s", expr) -- print as a symbol
    end
  else
    prindent("%s", expr)
  end
end

local function pprint(string, indent)
  eg_produced = match(sexpr, string)
  pprints(eg_produced, indent or "")
end


if arg[1] then pprint(arg[1]) end
local out = io.read("a")
print(pprint(out))
return pprint
