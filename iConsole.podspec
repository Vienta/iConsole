Pod::Spec.new do |s|
  s.name     = 'iConsole'
  s.version  = '1.0.0'
  s.license  = 'zlib'
  s.summary  = '本库是对iConsole（https://github.com/nicklockwood/iConsole）的扩展，主要增加了搜索关键字的功能，利于调试'
  s.homepage = 'https://github.com/Vienta/iConsole'
  s.authors  = 'Nick Lockwood'
  s.source   = { :git => 'https://github.com/Vienta/iConsole.git', :tag => s.version }
  s.source_files = 'iConsole'
  s.requires_arc = true
  s.ios.deployment_target = '5.0'

  s.subspec 'GTM' do |ss|
    ss.source_files = 'iConsole/GTM/*.{h,m}'
  end

end
