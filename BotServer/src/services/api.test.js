import api from './api';

global.fetch = jest.fn();

describe('api.sendCoordinates', () => {
  beforeEach(() => {
    fetch.mockClear();
  });

  it('should send coordinates and return the response data', async () => {
    const mockResponse = { success: true };
    fetch.mockResolvedValueOnce({
      ok: true,
      json: async () => mockResponse,
    });

    const latitude = 40.7128;
    const longitude = -74.0060;
    const result = await api.sendCoordinates(latitude, longitude);

    expect(fetch).toHaveBeenCalledWith('/api/send-coordinates', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify({ latitude, longitude }),
    });

    expect(result).toEqual(mockResponse);
  });

  it('should throw an error if the API response is not ok', async () => {
    fetch.mockResolvedValueOnce({
      ok: false,
      json: async () => ({ message: 'Invalid coordinates' }),
    });

    const latitude = 40.7128;
    const longitude = -74.0060;

    await expect(api.sendCoordinates(latitude, longitude)).rejects.toThrow(
      'Invalid coordinates'
    );
  });
});