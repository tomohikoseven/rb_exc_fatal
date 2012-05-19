$LOAD_PATH << "."
require 'libfatal'

# main thread
begin
    # sub thread
    t = Thread.new do
        
        begin
            fatal = Fatal.new
            fatal.do_fatal
        rescue Fatal
            puts "sub thread rescue!"
        end
    end

puts "sleep 3..."
sleep 3
#t.join
rescue Fatal
    puts "main thread rescue!"
end
