import os
import wave
import numpy as np
from numpy import array, arange, abs as np_abs
from numpy.fft import rfft, rfftfreq

types = {
    1: np.int8,
    2: np.int16,
    4: np.int32
}

def transform(st):
	inFiles = os.listdir('./wav/' + st)
	File = open('./predictors/' + st, 'w')
	print(len(inFiles), file=File)
	for i in range(len(inFiles)):
		wav = wave.open('./wav/' + st + '/' + inFiles[i], mode="r")
		(nchannels, sampwidth, FD, N, comptype, compname) = wav.getparams()
		samples = np.fromstring(wav.readframes(N), dtype=types[sampwidth])
		spectrum = rfft(samples)
		print(len(spectrum), file=File)
		for j in range(len(spectrum)):
			print(np_abs(spectrum[j]) / N, end=' ', file=File)
		print(file=File)
		RFFT = rfftfreq(N, 1. / FD)
		for j in range(len(RFFT)):
			print(RFFT[j], end=' ', file=File)
		print(file=File)

transform('broken')
transform('whole')

