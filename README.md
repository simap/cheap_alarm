
# Cheap Alarm Controller

I created Cheap Alarm to help ward off theives. Something that I could put together in an hour or two and not worry about losing. 


1. Cheap 120db 12v peizo siren - $3.50
1. Arduino nano clone - $2.50
1. Power mosfet - $1
1. PIR motion sensor - $2
1. Perf board $1

# What it does

The arduino in there to provide a bit of smarts during power on and alarm states. When first powered, the PIR sensor detection pin is high until it settles down, so the Arduino sleeps for a bit at first.

The arduino also keeps the alarm going for at least 30s, and in 30s increments thereafter as long as motiion is detected.

There's also a small delay between triggering and when the siren starts.

It chirps the siren during power on, much less time than the PIR sensor would trigger for. Enough to know its working, but not enough to wake everyone up if there's a power blip in the middle of the night.




