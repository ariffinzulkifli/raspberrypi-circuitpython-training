# require library - sudo pip3 install adafruit-circuitpython-irremote
import pulseio
import board
import adafruit_irremote

pulsein = pulseio.PulseIn(board.D16, maxlen=120, idle_state=True)
decoder = adafruit_irremote.GenericDecode()


while True:
    pulses = decoder.read_pulses(pulsein)
    print("Heard", len(pulses), "Pulses:", pulses)
    try:
        code = decoder.decode_bits(pulses)
        print("Decoded:", code)
    except adafruit_irremote.IRNECRepeatException:  # unusual short code!
        print("NEC repeat!")
    except adafruit_irremote.IRDecodeException as e:# failed to decode
        print("Failed to decode: ", e.args)

    print("----------------------------")