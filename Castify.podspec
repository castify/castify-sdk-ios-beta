Pod::Spec.new do |s|
  s.name = 'Castify'
  s.version = '1.0.0-RC.1'
  s.summary = 'Castify SDK for iOS.'
  s.license = {
    :type => "Copyright",
    :text => "Copyright (C) Castify, Inc."
  }
  s.author = { 'shun_fu' => 'developers@castify-inc.com' }
  s.source = { 
    :git => 'git@github.com:castify/castify-sdk-ios-beta.git', 
    :tag => s.version.to_s 
  }
  s.homepage = 'https://castify.jp/'
  s.vendored_frameworks = 'Castify.xcframework'
  s.frameworks = [
    'AVFoundation', 
    'AudioToolBox',
    'VideoToolBox'
  ]
  s.ios.deployment_target = '10.0'
end
