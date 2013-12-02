-- defines a factorial function
--function fact (n)
--    if n == 0 then
--        return 1
--    else
--        return n * fact(n-1)
--    end
--end
--
--print("enter a number:")
--a = io.read("*number")        -- read a number
--print(fact(a))

local m = M()
m:set('key', 'val')
m:is_loaded("this,is,a,test")
m:prepend_path('PATH', '/usr/local/bin')
m:append_path('PATH', '/usr/local/bin')
print(m:sysinfo('SYSNAME'))
print(m:sysinfo('MACHINE'))
