Pod::Spec.new do |s|
  s.name = 'Castify'
  s.version = '0.1.0'
  s.summary = 'Castify SDK for iOS.'
  s.license = {
    :type => "Copyright",
    :text => "Copyright (C) Evaluni, Inc."
  }
  s.author = { 'shun_fu' => 'shun_fu@evaluni.com' }
  s.source = { 
    :git => 'git@github.com:castify/castify-sdk-ios-beta.git', 
    :tag => s.version.to_s 
  }
  s.homepage = 'https://castify.jp/'
  s.vendored_frameworks = 'Castify.framework'
  s.frameworks = [
    'AVFoundation', 
    'AudioToolBox',
    'VideoToolBox'
  ]
  s.ios.deployment_target = '10.0'
end
