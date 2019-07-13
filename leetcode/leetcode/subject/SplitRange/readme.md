### 描述
之前写视频边下边播时遇到的场景，从AVPlayer过来一个请求，请求中有个range，本地有很多缓存碎片，需要根据这些缓存range，将请求range划分成多个range，在缓存中的，是local range，后续会根据这个range从磁盘取数据。不在缓存中的，会走网络请求。
