var TimeLimitedCache = function() {
  this.cache = new Map();
};

TimeLimitedCache.prototype.set = function(key, value, duration) {
  const now = Date.now();
  const expirationTime = now + duration;
  
  if (this.cache.has(key)) {
      const existingEntry = this.cache.get(key);
      if (existingEntry.expirationTime > now) {
          clearTimeout(existingEntry.timeoutId);
          this.cache.set(key, { value, expirationTime, timeoutId: setTimeout(() => this.cache.delete(key), duration) });
          return true;
      }
  }
  
  this.cache.set(key, { value, expirationTime, timeoutId: setTimeout(() => this.cache.delete(key), duration) });
  return false;
};

TimeLimitedCache.prototype.get = function(key) {
  const now = Date.now();
  if (this.cache.has(key)) {
      const entry = this.cache.get(key);
      if (entry.expirationTime > now) {
          return entry.value;
      }
      this.cache.delete(key);  // Clean up expired entry
  }
  return -1;
};

TimeLimitedCache.prototype.count = function() {
  let count = 0;
  const now = Date.now();
  this.cache.forEach((entry) => {
      if (entry.expirationTime > now) {
          count++;
      }
  });
  return count;
};